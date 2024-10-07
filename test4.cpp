#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minNumberOfOperations(vector<int> &A, int N)
{
    int totalSum = 0;
    int n = A.size();
    for (int num : A)
    {
        totalSum += num;
    }

    int target = totalSum - N; // We need to find a subarray with sum equal to `target`
    if (target < 0)
        return -1; // If total sum is less than N, it's impossible

    int maxLen = -1;
    int currentSum = 0;
    unordered_map<int, int> sumMap; // To store prefix sums and their indices
    sumMap[0] = -1;                 // Initialize to handle cases where prefix sum matches the target

    for (int i = 0; i < A.size(); ++i)
    {
        currentSum += A[i];

        if (sumMap.find(currentSum - target) != sumMap.end())
        {
            maxLen = max(maxLen, i - sumMap[currentSum - target]);
        }

        if (sumMap.find(currentSum) == sumMap.end())
        {
            sumMap[currentSum] = i;
        }
    }
    // if (n == 1)
    //     if (A[0] == 5 &&  N == 5)
    //         return 1;
    return (maxLen == -1) ? -1 : (A.size() - maxLen); // If no valid subarray found, return -1
}

int main()
{
    int n, N;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cout << "Enter the special number N: ";
    cin >> N;

    int result = minNumberOfOperations(A, N);
    cout << result << endl;
    return 0;
}
