https://leetcode.com/problems/two-sum/
class Solution { 
    // ----------------------------------------------------------------------------brute force
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;int flag;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);
                flag++;
                break;
            }
            }
        }
            if(flag)
            return ans;
            else
            ans.push_back(-1);
            return ans;
        }
    };
// ---------------------optimised approach using hashmap in O(N) time complexity
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for (int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            int moreneeded=target-n;
            if(mpp.find(moreneeded)!=mpp.end())
            {
                return{mpp[moreneeded],i};
            }
            mpp[n]=i;
        }
        return{-1,-1};
    }
};
