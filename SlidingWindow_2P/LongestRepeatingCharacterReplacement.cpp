class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;int right=0;
        int maxlen=0;
        int maxf=0;
        int hsh[26]={0};
        while(right<s.size())
        {
            hsh[s[right]-'A']++;
            maxf=max(maxf,hsh[s[right]-'A']);
            int len=right-left+1;
            while(len - maxf >k)
            {
                hsh[s[left]-'A']--;
                left++;
                len=right-left+1;
            }
            if(len - maxf <=k)
            {
                maxlen=max(maxlen,len);
            }
            right++;
        }
        return maxlen;
    }
};