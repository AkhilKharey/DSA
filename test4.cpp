#include <iostream>
using namespace std;

long long andyTrucker(int N, int K, long long *A)
{
    // Edge case: if K > N, it's not possible to pick K consecutive elements
    if (K > N)
    {
        return -1;
    }

    // Calculate the initial sum of the first K elements
    long long currentSum = 0;
    for (int i = 0; i < K; i++)
    {
        currentSum += A[i];
    }

    // Initialize maxWeight with the sum of the first K elements
    long long maxWeight = currentSum;

    // Slide the window across the array
    for (int i = K; i < N; i++)
    {
        // Slide the window by removing the first element of the previous window
        // and adding the next element in the array
        currentSum = currentSum - A[i - K] + A[i];

        // Update maxWeight if the new currentSum is greater
        if (currentSum > maxWeight)
        {
            maxWeight = currentSum;
        }
    }

    return maxWeight;
}

int main()
{
    int N, K;
    cout << "Enter the number of elements (N) and the window size (K): ";
    cin >> N >> K;

    // Dynamic array to hold the input values
    long long *A = new long long[N];
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // Call the function and display the result
    long long result = andyTrucker(N, K, A);
    if (result != -1)
    {
        cout << "Maximum sum of " << K << " consecutive elements is: " << result << endl;
    }
    else
    {
        cout << "Window size K is larger than the array size N." << endl;
    }

    // Free the dynamically allocated memory
    delete[] A;

    return 0;
}
