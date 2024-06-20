class Solution {
public:
    int maxProduct(vector<int>& nums) {
       double  pre=1;
       double suf=1;
        int maxp=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre=pre*nums[i];
            suf*=nums[n-i-1];
            // maxp=max(maxp,max(pre,suf)); its substitute is below because of double due to one test casae which was not passing
            double temp=pre;
            if(pre<suf)   temp=suf;
            if(maxp<temp)  maxp=temp;
        }
        return maxp;
    }
};