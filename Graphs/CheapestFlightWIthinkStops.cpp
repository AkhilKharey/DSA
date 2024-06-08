class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i:flights)
        {
            adj[i[0]].push_back({i[1],i[2]});   
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>lowestPrice(n,1e9);
       lowestPrice[src]=0;
        while(!q.empty())
        {
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            q.pop();
            for(auto temp:adj[node])
            {
                int adjNode=temp.first;
                int edgeW=temp.second;
                if(cost+edgeW<lowestPrice[adjNode] && stops<=k)
                {
               lowestPrice[adjNode]=cost+edgeW;
               q.push({stops+1,{adjNode,lowestPrice[adjNode]}});
                }
            }
        }
        if(lowestPrice[dst]==1e9)
        return -1;
        else
        return lowestPrice[dst];
    }
};