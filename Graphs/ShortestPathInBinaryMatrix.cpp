class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // n*m
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>>distance(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>>q;
     q.push({1,{0,0}});
     distance[0][0]=1;
     if(grid[0][0]==1)
     return -1;
     while(!q.empty())
     {
         auto it=q.front();
         int dis=it.first;
         int row=it.second.first;
         int col=it.second.second;
         q.pop();
         for(int delrow=-1;delrow<=1;delrow++)
         {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 
                && dis+1<distance[nrow][ncol])
                {
                    distance[nrow][ncol]=dis+1;
                    q.push({1+dis,{nrow,ncol}});
                }
            }
         }
     }
     if(distance[n-1][n-1]==1e9)
     return -1;
     else 
     return distance[n-1][n-1];
    }
};