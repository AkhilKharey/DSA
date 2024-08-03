class Solution
{
public:
  int SumLessThanGoal(vector<int> &nums, int goal)
  {
    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;
    if (goal < 0)
      return 0;
    while (right < nums.size())
    {
      sum += nums[right];
      while (sum > goal)
      {
        sum = sum - nums[left];
        left++;
      }
      if (sum <= goal)
        count += right - left + 1;
      right++;
    }
    return count;
  }
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    return (SumLessThanGoal(nums, goal) - SumLessThanGoal(nums, goal - 1));
  }
};