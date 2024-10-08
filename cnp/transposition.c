#include <stdio.h>
#include <string.h>

#define MAX_ROWS 20 // Maximum number of rows in the cipher matrix
#define KEY_LEN 8   // Length of the keyword

// Function to generate the sequence array based on the keyword
void generate_sequence(char keyword[], int seq[])
{
    int i, j, count;

    // For each character in the keyword
    for (i = 0; i < KEY_LEN; i++)
    {
        count = 0;
        // Count how many characters in the keyword are less than the current character
        for (j = 0; j < KEY_LEN; j++)
        {
            if (keyword[i] > keyword[j])
                ++count;
        }
        seq[i] = count;
    }
}

int main()
{
    char data[100], keyword[] = "MEGABUCK", cipher[MAX_ROWS][KEY_LEN];
    int seq[KEY_LEN], data_len;
    int i, j, k;

    // Step 1: Generate the sequence array from the keyword
    generate_sequence(keyword, seq);

    // Step 2: Input the data to be encrypted
    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove newline character

    data_len = strlen(data);
    int rows = (data_len + KEY_LEN - 1) / KEY_LEN; // Calculate number of rows

    // Step 3: Initialize cipher array with '.'
    for (i = 0; i < rows; i++)
        for (j = 0; j < KEY_LEN; j++)
            cipher[i][j] = '.';

    // Step 4: Fill the cipher matrix row-wise with the data
    for (i = 0; i < data_len; i++)
        cipher[i / KEY_LEN][i % KEY_LEN] = data[i];

    // Step 5: Encrypt the data
    char encrypted_data[MAX_ROWS * KEY_LEN + 1];
    int index = 0;

    // Read columns based on the sequence and store in encrypted_data
    for (i = 0; i < KEY_LEN; i++)
    {
        // Find the column in cipher that corresponds to the sequence number i
        for (j = 0; j < KEY_LEN; j++)
        {
            if (seq[j] == i)
            {
                // Copy the column to encrypted_data
                for (k = 0; k < rows; k++)
                {
                    encrypted_data[index++] = cipher[k][j];
                }
                break;
            }
        }
    }
    encrypted_data[index] = '\0'; // Null-terminate the encrypted data

    // Step 6: Display the encrypted data
    printf("\nEncrypted data:\n");
    printf("%s\n", encrypted_data);

    // Step 7: Decrypt the data
    // Re-initialize index for decryption
    index = 0;

    // Fill the cipher matrix column-wise based on the sequence
    for (i = 0; i < KEY_LEN; i++)
    {
        // Find the column in cipher that corresponds to the sequence number i
        for (j = 0; j < KEY_LEN; j++)
        {
            if (seq[j] == i)
            {
                // Copy data from encrypted_data into the cipher matrix
                for (k = 0; k < rows; k++)
                {
                    cipher[k][j] = encrypted_data[index++];
                }
                break;
            }
        }
    }

    // Step 8: Reconstruct the original data by reading the cipher matrix row-wise
    char decrypted_data[data_len + 1];
    index = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < KEY_LEN; j++)
        {
            // Only copy actual data, ignore padding characters
            if (cipher[i][j] != '.' && index < data_len)
            {
                decrypted_data[index++] = cipher[i][j];
            }
        }
    }
    decrypted_data[index] = '\0'; // Null-terminate the decrypted data

    // Step 9: Display the decrypted data
    printf("\nDecrypted data:\n");
    printf("%s\n", decrypted_data);

    return 0;
}
