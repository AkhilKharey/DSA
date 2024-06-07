class Solution {
public:

   bool dfs(int node,int colour,vector<int>&color,vector<vector<int>>&graph)
   {
       color[node]=colour;
       for(auto temp: graph[node])
       {
         if(color[temp]==-1)
         {
            if( dfs(temp,!colour,color,graph) ==false)
            return false;
         }
         else if(color[temp]==colour)
         {
             return false;
         }
       }
       return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);

        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false)
                return false;
            }
        }
        return true;
    }
};