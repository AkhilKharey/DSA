#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int calculateMaxQuality(int impactFactor, vector<int> ratings)
{
    int n = ratings.size();
    int maxAmplifyScore = INT_MIN;
    int maxAdjustScore = INT_MIN;

    auto kadane = [](const vector<int> &arr)
    {
        int maxSum = INT_MIN, currentSum = 0;
        for (int value : arr)
        {
            currentSum += value;
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    };

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            vector<int> modifiedRatings = ratings;

            for (int k = i; k <= j; ++k)
            {
                modifiedRatings[k] *= impactFactor;
            }
            maxAmplifyScore = max(maxAmplifyScore, kadane(modifiedRatings));

            modifiedRatings = ratings;
            for (int k = i; k <= j; ++k)
            {
                if (modifiedRatings[k] >= 0)
                {
                    modifiedRatings[k] = floor(modifiedRatings[k] / (double)impactFactor);
                }
                else
                {
                    modifiedRatings[k] = ceil(modifiedRatings[k] / (double)impactFactor);
                }
            }
            maxAdjustScore = max(maxAdjustScore, kadane(modifiedRatings));
        }
    }

    return max(maxAmplifyScore, maxAdjustScore);
}

int main()
{
    int impactFactor;
    cin >> impactFactor;

    int n;
    cin >> n;

    vector<int> ratings(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ratings[i];
    }

    cout << calculateMaxQuality(impactFactor, ratings) << endl;

    return 0;
}