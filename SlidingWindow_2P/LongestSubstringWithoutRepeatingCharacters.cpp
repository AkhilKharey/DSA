class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        unordered_map<char,int>mp;
        int len,maxlen=INT_MIN;
        if(s.empty())
        return 0;
        while(r<s.size())
        {
          
          if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l)
          {
            l=mp[s[r]]+1;
          }
          mp[s[r]]=r;
        len=r-l+1;
        maxlen=max(maxlen,len);
        r++;
        }
        return maxlen;
    }
};