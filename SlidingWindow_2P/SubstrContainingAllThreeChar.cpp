class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int right=0;
        unordered_map<char,int>mp;
        int count=0;
        while(left<s.size())
        {
            char ch=s[right];
            mp[ch]++;

            if(mp.size()==3)
            {
                count++;
            }
          if(right==s.size()-1)
          {
            mp.clear();
            left++;
            right=left-1;
          }
          right++;
        }
        return count;
    }
};