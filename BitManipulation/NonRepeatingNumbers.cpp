//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
  {
        // Code here.
        
        int xorr=0;
        for(auto i:nums)
        xorr=xorr^i;
        int count=0;
        while(xorr)
        {
         if(xorr&1)
         break;
         count++;
         xorr=xorr>>1;
        }
        int xor1=0;int xor2=0;
        for(auto i:nums)
        {
            if(i&1<<count)
            xor1=xor1^i;
            else
            xor2=xor2^i;
        }
        vector<int>ans;
        ans.push_back(xor1);
        ans.push_back(xor2);
        
        sort(ans.begin(),ans.end());
        return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends