class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int ans=1e9;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>Difference(heights.size(),vector<int>(heights[0].size(),1e9));
      Difference[0][0]=0;
        while(!pq.empty())
        {
        auto it=pq.top();
        pq.pop();
      int  maxDiff=it.first;
        int row=it.second.first;
        int col=it.second.second;
       for(int i=0;i<4;i++)
       {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
         if(nrow>=0 && nrow<heights.size() && ncol>=0 && ncol<heights[0].size() )
         {
            int newEffort=max(abs(heights[row][col]-heights[nrow][ncol]),maxDiff);
            if(newEffort<Difference[nrow][ncol])
            {
                Difference[nrow][ncol]=newEffort;
                pq.push({newEffort,{nrow,ncol}});
            }
         }
       }
        }
        return Difference[heights.size()-1][heights[0].size()-1];
    }
};