class Solution {
public:
    int subarrayWithLessThanKDistinct(vector<int>& nums,int k)
    {
        int left=0;
        int right=0;
        int cnt=0;
        unordered_map<int,int>mp;
        if(k<0)
        return 0;
        while(right<nums.size())
        {
            mp[nums[right]]++;
            while(mp.size()>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                mp.erase(nums[left]);
                left++;
            }
            if(mp.size()<=k)
            {
                // we are aadding size of the array here instead of +1 because if a 
                // subarray is valis in this question then all the part of that subarray will also be valid
                cnt+=right-left+1;
            }
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return( subarrayWithLessThanKDistinct(nums,k)- subarrayWithLessThanKDistinct(nums,k-1));
    }
};