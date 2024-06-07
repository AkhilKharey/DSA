class Solution {
public:
    void  traversal(int i,vector<int>&visited,vector<vector<int>>& isConnected)
    {
        queue<int>q;
      q.push(i);
      visited[i]=1;
      while(!q.empty())
      {
          int temp=q.front();
          q.pop();
          for(int i=0;i<isConnected.size();i++)
          {
              if(isConnected[temp][i]==1)
              if(!visited[i])
              {
                  q.push(i);
                  visited[i]=1;
              }
          }
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       vector<int>visited(isConnected.size());
       int provinces=0;
      
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
            traversal(i,visited,isConnected);
            provinces++;
            }
        }
     return provinces;
    }
};