class Solution {
public:
    int numberofSubarrayWithOddLessThanK(vector<int>& nums,int k)
    {
        int left=0;
        int right=0;
        int sum=0;
        int count=0;
        int goal=k;
        if(k<0)
        return 0;
         while(right<nums.size())
        {
            sum+=nums[right]%2;
            while(sum>goal)
            {
              sum =sum-nums[left]%2 ;
              left++;
            }
            if(sum<=goal)
             count+=right-left+1;

            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return(numberofSubarrayWithOddLessThanK(nums,k)-numberofSubarrayWithOddLessThanK(nums,k-1));
    }
};