//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.length()%2!=0)
    return -1;
    stack<char> st;
   int ob=0,cb=0;
    for(auto &ch:s)
    {
        if(ch=='{')
        {
        st.push(ch);
        ob++;
        }
        else if(ch=='}')
        {
            if(st.empty())
            {
            st.push(ch);
                cb++;
            }
            else
            {
                if(st.top()=='{')
                {
                st.pop();
                ob--;    
                }
                else
                {
                st.push(ch);
                cb++;
                }
            }
        }
    }
    int ans=(ob+1)/2 + (cb+1)/2;
    return ans;
}