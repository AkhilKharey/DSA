        // ---------------------------------------------------------------------------better approach O(nlogn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second >nums.size()/2)
            return i.first;
        }
        return 0;
    }
};
// -------------------------------------------------------------moores voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;int count=0;

        for(int i=0;i<nums.size();i++)
        {
            int current_element=nums[i];
            if(count==0)
            element=current_element;

            if(current_element==element)
            count++;
            
            else
            count--;
        }
        count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)
            count++;
        }
        if(count>nums.size()/2)
        return element;
        else
        return -1;
    }
};