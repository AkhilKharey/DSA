//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int left=0;
    int right=0;
    int maxlen=-1;
    unordered_map<char,int>mp;
    while(right<s.size())
    {
        char ch=s[right];
        mp[ch]++;
        if (mp.size()>k)
        {
         mp[s[left]]--;
         if(mp[s[left]] == 0)
         {
             mp.erase(s[left]);
         }
         left++;
        }
        if(mp.size()==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends