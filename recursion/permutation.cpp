// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
// --------------------------------------------------------------------approach1 with extra space
class Solution {
    private:
     void solve(vector<vector<int>>&ans ,int map[],
     vector<int>&nums,vector<int>&ds)
     {
       if(ds.size()==nums.size())
       {
        ans.push_back(ds);
        return;
       }
       for(int i=0;i<nums.size();i++)
       {
          if(map[i]==0)
          {
            ds.push_back(nums[i]);
            map[i]=1;
            solve(ans,map,nums,ds);
            ds.pop_back();
            map[i]=0;
          }
       }
     }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        int map[n];
        memset(map,0,sizeof(map));
        vector<int>ds;
        solve(ans,map,nums,ds);
        return ans;
    }
};
// --------------------------------------------------------------------Approach2
class Solution {
public:
void permutation(int ind,vector<vector<int>> &ans,vector<int> &arr)
{
    if(ind==arr.size())
    {
        ans.push_back(arr);
        return;
    }
     for(int i=ind;i<arr.size();i++)
     {
         swap(arr[i],arr[ind]);
         permutation(ind+1,ans,arr);
         swap(arr[i],arr[ind]);
     }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(0,ans,nums);
        return ans;
        
    }
};