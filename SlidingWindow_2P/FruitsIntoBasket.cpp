//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
    
         int left=0;
         int right=0;
         int maxlen=0;
         vector<int>arr(fruits);
         unordered_map<int,int>mpp;
         while(right<N)
         {
             mpp[arr[right]]++;
             if(mpp.size()>2)
             {
                 mpp[arr[left]]--;
                 if(mpp[arr[left]]==0)
                 {
                     mpp.erase(arr[left]);
                 }
                     left++;
             }
             if(mpp.size()<=2)
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends