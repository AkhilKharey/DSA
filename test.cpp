#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

// Function to count the number of set bits in an integer
int countSetBits(int n)
{
    return __builtin_popcount(n);
}

// Recursive function to simulate the K transformations and check if the result is 1
bool transformTo1(int x, int k)
{
    while (k > 0 && x > 1)
    {
        x = countSetBits(x);
        k--;
    }
    return x == 1 && k == 0;
}

int decryptions(string N, int K)
{
    int upperLimit = stoi(N, nullptr, 2); // Convert binary string N to an integer
    int count = 0;

    for (int i = 1; i <= upperLimit; ++i)
    {
        if (transformTo1(i, K))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string N;
    int K;

    cin >> N;
    cin >> K;

    cout << decryptions(N, K) << endl;
    return 0;
}
