class Solution {
public:

    int delrow[4]={0,-1,0,1};
    int delcol[4]={-1,0,1,0};
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid)
    {
        visited[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&
            !visited[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && grid[0][i]==1)
            {
            dfs(0,i,visited,grid);
            }
            if(!visited[n-1][i] && grid[n-1][i]==1)
            {
             dfs(n-1,i,visited,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0]&& grid[i][0]==1)
            {
             dfs(i,0,visited,grid);
            }
            if(!visited[i][m-1] && grid[i][m-1]==1)
            {
            dfs(i,m-1,visited,grid);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                 ans++;
            }
        }
        return ans;
    }
};