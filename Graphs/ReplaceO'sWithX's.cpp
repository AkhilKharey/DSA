//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int delrow[4]={0,-1,0,1};
     int delcol[4]={-1,0,1,0};
    void dfs(int row,int col, vector<vector<int>>&visited, vector<vector<char>>&mat)
    {
        visited[row][col]=1;
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size() && !visited[nrow][ncol]
            && mat[nrow][ncol]=='O' )
            {
                dfs(nrow,ncol,visited,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        
        for(int i=0;i<m;i++)
        {
            // for first row
            if(!visited[0][i] && mat[0][i]=='O')
            {
                dfs(0,i,visited,mat);
            }
            // for last row
            if(!visited[n-1][i] && mat[n-1][i]=='O')
            {
                dfs(n-1,i,visited,mat);
            }
        }
        
          for(int i=0;i<n;i++)
        {
            // for first column
            if(!visited[i][0] && mat[i][0]=='O')
            {
                dfs(i,0,visited,mat);
            }
            // for last column
            if(!visited[i][m-1] && mat[i][m-1]=='O')
            {
                dfs(i,m-1,visited,mat);
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==1)
                ans[i][j]='O';
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends