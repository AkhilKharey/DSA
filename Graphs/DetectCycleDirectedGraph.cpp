//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>&visited ,vector<int>&pathVisit,vector<int>adj[])
    {
        visited[node]=1;
        pathVisit[node]=1;
        // traverse for adjacent nodes
        for(auto i:adj[node])
        {
            // if the noode is not visited
            if(!visited[i])
            {
                
            if(dfs(i,visited,pathVisit,adj)==true)
            return true;
            }
            // if the node is visited and in the same path then the cycle is present
            else if(pathVisit[i])
            {
                return true;
            }
        }
        pathVisit[node]=0;
        return false;
    }
    // to use single visited  array instead of 2 we can mark 2 for path visited and for visited 1
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>pathVisit(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            if(dfs(i,visited,pathVisit,adj)==true)
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
// ---------------------------------------------------------------------approach 2 using kahns algorithm bfs
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int indegree[V]={0};
        for(int i=0;i<V;i++)
        {
            for(auto temp:adj[i])
            {
                
            indegree[temp]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto temp:adj[node])
            {
                indegree[temp]--;
                if(indegree[temp]==0)
                q.push(temp);
            }
        }
        if(topo.size()<V)
        return true;
        else
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends