// https://leetcode.com/problems/jump-game/
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxIndex)
                return false;
            int jumpToIndex = i + nums[i];
            maxIndex = max(maxIndex, jumpToIndex);
        }
        if (maxIndex >= nums.size() - 1)
            return true;
        return false;
    }
};