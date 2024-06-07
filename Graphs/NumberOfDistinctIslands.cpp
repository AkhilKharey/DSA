//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
  int delrow[4]={0,-1,0,1};
  int delcol[4]={-1,0,1,0};
    void dfs(int row,int col,vector<vector<int>>&visited , vector<vector<int>>&grid,vector<pair<int,int>>&vec,
    int rowbase,int colbase)
    {
        visited[row][col]=1;
        vec.push_back({row-rowbase,col-colbase});
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() 
            && !visited[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,visited,grid,vec,rowbase,colbase);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,visited,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends