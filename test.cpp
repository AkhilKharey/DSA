#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bitset>

using namespace std;

const int MOD = 1e9 + 7;

// Function to count the number of set bits in an integer
int countSetBits(int n)
{
    return __builtin_popcount(n);
}

// Function to precompute the number of steps to reach 1 for each number up to maxNum
vector<int> precomputeSteps(int maxNum)
{
    vector<int> steps(maxNum + 1, -1); // Initialize with -1 meaning uncomputed
    queue<int> q;

    // Start with number 1, which requires 0 steps to become 1
    steps[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        int currentSteps = steps[num];

        // Calculate the next number in the sequence
        int nextNum = countSetBits(num);
        if (nextNum <= maxNum && steps[nextNum] == -1)
        {
            steps[nextNum] = currentSteps + 1;
            q.push(nextNum);
        }
    }

    return steps;
}

// Function to count how many numbers can be reduced to 1 in exactly K steps
int decryptions(const string &N, int K)
{
    int upperLimit = stoi(N, nullptr, 2); // Convert binary string N to an integer
    vector<int> steps = precomputeSteps(upperLimit);
    int count = 0;

    for (int num = 1; num <= upperLimit; ++num)
    {
        if (steps[num] == K)
        {
            count++;
        }
    }

    return count % MOD;
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
