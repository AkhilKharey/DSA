#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Recursive function to find the minimum time to reach station i on line A or B
int minTimeA(int A[], int B[], int i, int X, int Y, vector<int> &memoA, vector<int> &memoB);
int minTimeB(int A[], int B[], int i, int X, int Y, vector<int> &memoA, vector<int> &memoB);

int minTimeA(int A[], int B[], int i, int X, int Y, vector<int> &memoA, vector<int> &memoB)
{
    if (i == 0)
        return A[0]; // Base case: the time to reach the first station on line A

    if (memoA[i] != -1)
        return memoA[i]; // Return memoized value if already computed

    // Recursive step: compute the minimum time to reach station i on line A
    memoA[i] = min(minTimeA(A, B, i - 1, X, Y, memoA, memoB) + A[i],
                   minTimeB(A, B, i - 1, X, Y, memoA, memoB) + Y + A[i]);
    return memoA[i];
}

int minTimeB(int A[], int B[], int i, int X, int Y, vector<int> &memoA, vector<int> &memoB)
{
    if (i == 0)
        return B[0]; // Base case: the time to reach the first station on line B

    if (memoB[i] != -1)
        return memoB[i]; // Return memoized value if already computed

    // Recursive step: compute the minimum time to reach station i on line B
    memoB[i] = min(minTimeB(A, B, i - 1, X, Y, memoA, memoB) + B[i],
                   minTimeA(A, B, i - 1, X, Y, memoA, memoB) + X + B[i]);
    return memoB[i];
}

int solution(int A[], int B[], int N, int X, int Y)
{
    vector<int> memoA(N, -1), memoB(N, -1); // Initialize memoization vectors
    return min(minTimeA(A, B, N - 1, X, Y, memoA, memoB),
               minTimeB(A, B, N - 1, X, Y, memoA, memoB));
}

int main()
{
    // Test case 1
    int A1[] = {1, 6, 2};
    int B1[] = {3, 2, 5};
    int N1 = 3, X1 = 2, Y1 = 1;
    cout << solution(A1, B1, N1, X1, Y1) << endl; // Expected output: 8

    // Test case 2
    int A2[] = {12, 11, 4, 4};
    int B2[] = {9, 2, 5, 11};
    int N2 = 4, X2 = 8, Y2 = 4;
    cout << solution(A2, B2, N2, X2, Y2) << endl; // Expected output: 21

    // Test case 3
    int A3[] = {1, 10, 11};
    int B3[] = {10, 1, 10};
    int N3 = 3, X3 = 1, Y3 = 5;
    cout << solution(A3, B3, N3, X3, Y3) << endl; // Expected output: 9

    // Test case 4
    int A4[] = {8, 3, 3};
    int B4[] = {6, 1, 10};
    int N4 = 3, X4 = 4, Y4 = 3;
    cout << solution(A4, B4, N4, X4, Y4) << endl; // Expected output: 13

    return 0;
}
