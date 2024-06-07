class Solution {
    private:
      bool detectcycle(int node,vector<int>&visited ,vector<int>&pathVisited,vector<int>&check,vector<vector<int>>&graph)
      {
        visited[node]=1;
        pathVisited[node]=1;
        check[node]=0;
        for(auto temp:graph[node]){
                  if(!visited[temp])
                  {
                       if(detectcycle(temp,visited,pathVisited,check,graph)==true)
                       {
                        return true;
                       }
                  }
                  else if(pathVisited[temp])
                  {
                    return true;
                  }
        }
        check[node] = 1;
        pathVisited[node]=0;
        return false;
      }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
         vector<int>visited(V,0);
         vector<int>pathVisited(V,0);
         vector<int>check(V,0);
         vector<int>safeNodes;
         for( int i=0;i<V;i++)
         {
            if(!visited[i])
            {
                detectcycle(i,visited,pathVisited,check,graph);
            }
         }
        //  for(int i=0;i<V;i++)
        //  {
        //     if(check[i]==1)
        //     safeNodes.push_back(i);
        //  } OR
         for(int i=0;i<V;i++)
         {
            if(pathVisited[i]==0)
            safeNodes.push_back(i);
         }
         return safeNodes;
    }
};