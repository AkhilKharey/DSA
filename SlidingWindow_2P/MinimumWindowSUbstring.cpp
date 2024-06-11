class Solution {
public:
    string minWindow(string s, string t) {
        int hsh[256]={0};
        int left=0;
        int right=0;
        int minLen=1e9;
        int sidx=-1;
        int cnt=0;
        int m=t.size();
        int n=s.size();
        for(int i=0;i<m;i++)
        {
            hsh[t[i]]++;
        }
        while(right<n)
        {
            if(hsh[s[right]]>0)
            {
                cnt++;
            }
            hsh[s[right]]--;
            while(cnt==m)
            {
             if(right-left+1<minLen)
             {
                minLen=right-left+1;
                sidx=left;
             }
             hsh[s[left]]++;
             if(hsh[s[left]]>0)
             {
                cnt-=1;
             }
             left++;
            }
            right++;
        }
        return (sidx==-1?"":s.substr(sidx,minLen));
    }
};