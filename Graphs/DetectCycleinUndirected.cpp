// using bfs
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectcycle(int source,vector<int>adj[] ,vector<int> & visited)
    {
         queue<pair<int,int>>q;
        q.push({source,-1});
        visited[source]=1;
        
        while(!q.empty())
        {
            int parent=q.front().second;
            int node=q.front().first;
            q.pop();
            for(auto i: adj[node])
            {
                if(!visited[i])
                {
                    q.push({i,node});
                    visited[i]=1;
                }
                else if(visited[i] && i!=parent)
                return true;
            }
            
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
       
            
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectcycle(i,adj,visited)==true)
                return true;
            }
        }
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
// ---------------------------------------------------------------------------using dfs
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectcycle(int node,int parent,vector<int>adj[],vector<int>&visited)
    {
        visited[node]=1;
        
        for(auto i:adj[node])
        {
           if(!visited[i])
           {
           if( detectcycle(i,node,adj,visited)==true)
           return true;
           }
           else if(visited[i]&& i!=parent)
               return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectcycle(i,-1,adj,visited)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends