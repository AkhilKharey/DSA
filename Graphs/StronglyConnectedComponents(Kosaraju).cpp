//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
     void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,stack<int>&st)
     {
         visited[node]=1;
         
         for(auto i:adj[node])
         {
             if(!visited[i])  dfs(i,visited,adj,st);
         }
         
         st.push(node);    
     }
     void dfs2(int node,vector<int>&visited,vector<int>adj[])
     {
         visited[node]=1;
         
         for(auto i:adj[node])
         {
             if(!visited[i])  dfs2(i,visited,adj);
         }
         
     
     }
	public:
	//Function to find number of strongly connected components in the graph.
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>visited(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj,st);
            }
        }
        // for edge reversal we will take another adjancencuy list and store opposite edges in it
        vector<int>adjt[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=0;  //  making it zero to use it again in the next step
            for(auto it:adj[i])
            {
                // i->it   
                // and we need 
                // it->i
                adjt[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!visited[node])
            {
                scc++;
                dfs2(node,visited,adjt);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends