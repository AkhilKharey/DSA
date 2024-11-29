#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwap(int N, int K, int A[])
{
    int count = 0;       // Count of swaps performed
    bool swapped = true; // Flag to check if any swap happened in a pass
    while (swapped)
    {
        swapped = false; // Reset swap flag for the new pass
        for (int i = 0; i < N; i++)
        {
            if (A[i] > K)
            {
                // Perform the swap
                int temp = A[i];
                A[i] = K;
                K = temp;
                count++;
                swapped = true; // A swap has occurred
            }
        }
    }
    // Check if the array is sorted in increasing order
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return -1; // Impossible to sort
        }
    }
    return count; // Minimum number of swaps needed
}

int main()
{
    int N, K;
    cout << "Enter the length of the array and the value of K: ";
    cin >> N >> K;

    int A[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int result = minSwap(N, K, A);
    if (result != -1)
    {
        cout << "Minimum number of swaps to sort the array: " << result << endl;
    }
    else
    {
        cout << "It is impossible to sort the array." << endl;
    }

    return 0;
}
