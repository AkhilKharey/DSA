class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans;
        int n = nums.size();
        int sum = 0;
        vector<int> remCount(k + 1, 0);
        // find the prefix sum
        // prefixsum1%k=prefixsum2%k
        // then the prefixsum2-prefixsum1 is a multiple of k
        // we will count the occurences of each remainder
        // same remainder wale apas me pair bana skte hai valid subarray k liye to bs use count kar lenge

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            remCount[rem]++;
        }
        ans = remCount[0];
        for (int i = 0; i < k; i++)
        {
            int pairsWithSameRemainder = (remCount[i] * (remCount[i] - 1)) / 2;
            ans += pairsWithSameRemainder;
        }
        return ans;
    }
};