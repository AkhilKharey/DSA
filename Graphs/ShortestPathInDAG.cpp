class Solution {
    private:
    void dfs(int node,int destinationNode,vector<int>&visited,vector<pair<int,int>>adj[],vector<int>&ans,int dist,bool &flag)
    {
        visited[node]=1;
        if(node==destinationNode)
        {
            flag=true;
            ans[node]=min(dist,ans[node]);
             visited[node]=0;
            return;
        }
        for(auto temp:adj[node])
        {
            if(!visited[temp.first])
            {
                dist+=temp.second;
                dfs(temp.first,destinationNode,visited,adj,ans,dist,flag);
                dist-=temp.second;
            }
        }
        visited[node]=0;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
       vector<int>ans(N,INT_MAX);
        ans[0]=0;
        for(int i=1;i<N;i++)
        {
            vector<int>visited(N);
            bool flag=false;
            dfs(0,i,visited,adj,ans,0,flag);
            if(flag==false)
            ans[i]=-1;
        }
        return ans;
    }
};
// -----------------------------------------------------------better approach
class Solution {
    private:
    void dfs(int node,int vis[],vector<pair<int,int>>adj[],stack<int>&st){
        vis[node]=1;
        for(auto temp: adj[node])
        {
            if(!vis[temp.first])
            dfs(temp.first,vis,adj,st);
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        int visited[N]={0};
        stack<int>st;
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            dfs(i,visited,adj,st);
        }
        vector<int>dist(N,1e9);
        dist[0]=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            for(auto temp:adj[node])
            {
                if(dist[node]+temp.second<dist[temp.first])
                {
                    dist[temp.first]=dist[node]+temp.second;
                }
            }
            
        }
        for(int i=0;i<N;i++)
        {
            (dist[i]==1e9)?dist[i]=-1: dist[i]=dist[i];
        }
        return dist;
        
    }
};