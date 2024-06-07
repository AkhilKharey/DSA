class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<pow(2,nums.size());i++)
        {
            vector<int>subset;
            for(int j=0;j<nums.size();j++)
            {
                if(i & 1<<j)
                subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};