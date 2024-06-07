https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
----------------------recursive solution
class Solution {
public:
   void findCombination(int index,vector<int>& nums,vector<vector<int>> & ans,vector<int> & ds,int targetsum)
   {
       if (ds.size()==3)
       {
           if(targetsum==0)
           ans.push_back(ds);
           return;
       }
       for(int i=index;i<nums.size();i++)
       {
           if(i>index && nums[i]==nums[i-1])
               continue;
            // -----------------------------------------this will give tle


            ds.push_back(nums[i]);

            findCombination(i+1,nums,ans,ds,targetsum-nums[i]);

            ds.pop_back();
       }
return;
   }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
            int targetsum=0;
        findCombination(0,nums,ans,ds,targetsum);
        return ans;
    }
};
// --------------------------------------------------------------------brute solution 2  using set



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:------------------------------BRUTE FORCE WITH 3 FOR LOOP
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
// ------------------------------------------------------------------------better approach
// ------------------------------------------ek for loop kam lagega
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
       for(int i=0;i<nums.size();i++)
       {
           set<int>hashset;
           for(int j=i+1;j<nums.size();j++)
           {
               int third=-(nums[i]+nums[j]);
               if(hashset.find(third)!=hashset.end())
               {
                   vector<int>temp={nums[i],nums[j],third};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
               }
            hashset.insert(nums[j]);
           }
       } 
       vector<vector<int>>ans(st.begin(),st.end());

       return ans;
    }
};
// ------------------------------------------------------optimal solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            // to avoid duplicates
          if(i>0 && nums[i]==nums[i-1])
          continue;
           int j=i+1;
           int k=nums.size()-1;
           while(j<k)
           {
               int sum=nums[i]+nums[j]+nums[k];
               if(sum==0)
               {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;k--;
                // to  avoid duplicates
                 while(j<k&&nums[k]==nums[k+1])
                 k--;
                  while(j<k&&nums[j]==nums[j-1])
                 j++;
               }
               else if(sum>0)
               {
                 k--;
                
               }
               else
               {
                 j++;
                
               }
           }
        }
        return ans;
    }
};
