// https://leetcode.com/problems/string-to-integer-atoi/submissions/
class Solution {
 
public:
    int myAtoi(string s) {
        int it=0;
        while(it<s.length() && s[it]==' ')
        {
            it++;
        }
        if(it==s.length()) return 0;
        bool negative=false;
        int countToCheckIfMultiplePlusAndMinus=0;
        while(s[it]=='-')
        {
          negative=true;
          it++;
          countToCheckIfMultiplePlusAndMinus++;
        }
        while(s[it]=='+')
        {
            it++;
            countToCheckIfMultiplePlusAndMinus++;
        }
        // edge case
        if(countToCheckIfMultiplePlusAndMinus>1) return 0;
      long long  int ans=0;
      while(it<s.length() && s[it]>='0' && s[it]<='9')
      {
        int digit=s[it]-'0';
        ans=ans*10 + digit;
        if(ans>INT_MAX)
        {
            if(negative) return INT_MIN;
            return INT_MAX;
        }
        it++;
      }
        if(negative==true)
        ans=-ans;
        

        return ans;
    }
};