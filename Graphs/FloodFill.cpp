class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_color=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        visited[sr][sc]=1;
            int delrow[]={-1,0,0,1};
            int delcol[]={0,-1,1,0};
            int n=image.size();
            int m=image[0].size();
            image[sr][sc]=color;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && !visited[nrow][ncol] && image[nrow][ncol]==start_color)
                {
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};
// -----------------------------------------------------------------APPROACH2 using dfs
class Solution {
public:
   int delrow[4]={-1,0,0,1};
    int delcol[4]={0,-1,1,0};
    void dfs(int row,int col,int initial,int color,vector<vector<int>>&image,vector<vector<int>>&ans)
    {
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&  
            image[nrow][ncol]==initial && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,initial,color,image,ans);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,initial,color,image,ans);
        return ans;
    }
};