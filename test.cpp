#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// Function to calculate the maximum subarray sum
long maxSubarraySum(const vector<int> &arr)
{
    long max_current = arr[0];
    long max_global = arr[0];

    for (size_t i = 1; i < arr.size(); ++i)
    {
        max_current = max((long)arr[i], max_current + arr[i]);
        max_global = max(max_global, max_current);
    }
    return max_global;
}

long calculateMaxQualityScore(int impactFactor, vector<int> ratings)
{
    int n = ratings.size();
    long max_normal = maxSubarraySum(ratings);

    vector<int> diff(n);
    for (int i = 0; i < n; ++i)
    {
        diff[i] = ratings[i] * impactFactor - ratings[i];
    }
    long max_gain = maxSubarraySum(diff);
    long max_strategy1 = max_normal + max_gain;
    vector<int> adjusted_ratings(n);
    for (int i = 0; i < n; ++i)
    {
        if (ratings[i] >= 0)
        {
            adjusted_ratings[i] = ratings[i] / impactFactor;
        }
        else
        {
            adjusted_ratings[i] = (ratings[i] + impactFactor - 1) / impactFactor;
        }
        diff[i] = adjusted_ratings[i] - ratings[i];
    }
    max_gain = maxSubarraySum(diff);
    long max_strategy2 = max_normal + max_gain;
    return max(max_strategy1, max_strategy2);
}

int main()
{
    int n, impactFactor;
    cout << "Enter the number of ratings and the impact factor: ";
    cin >> n >> impactFactor;
    vector<int> ratings(n);
    cout << "Enter the ratings: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> ratings[i];
    }
    long max_quality_score = calculateMaxQualityScore(impactFactor, ratings);
    cout << "Maximum Quality Score: " << max_quality_score << endl;
    return 0;
}