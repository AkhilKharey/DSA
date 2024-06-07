class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
         int zeroCount=0;
         int maxLen=0;
         int len=0;
         while(right<nums.size())
         {
            if(nums[right]==0)
            zeroCount++;
            if(zeroCount>k)
            {
            while(zeroCount>k)
            {
                if(nums[left]==0)
                zeroCount--;

                left++;

            }
            }
            // ho sakta hai right wala zero ho pr zerocount k se kam ho to us zero wale ko bhi count karenge
            if(nums[right]==1 || zeroCount <=k )
            {
                 len=right-left+1;
                 maxLen=max(len,maxLen);
            }
            right++;
         }
         return maxLen;

    }
};