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