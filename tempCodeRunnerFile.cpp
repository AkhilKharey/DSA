#include <bits/stdc++.h>
using namespace std;

// Function to compute the number of solutions
int ArithmeticEquation(int N)
{
    const int MOD = 1000007;
    int count = 0;

    // Iterate over all possible values of x
    for (int x = N + 1; x <= 2 * N; ++x)
    {
        // Check if y is an integer
        if ((N * x) % (x - N) == 0)
        {
            count++;
        }
    }

    return count % MOD;
}

// Main function for testing
int main()
{
    int N;
    cin >> N;
    cout << ArithmeticEquation(N) << endl;
    return 0;
}