//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum=0;
        // in this question we dont need to store the parent because wee are not asked to 
        // print the mst just minimum sum is needed. 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> visited(V,0);
        // vector<pair<int,int>>mst; if asked to print the mst edges
        // {wt,node}
        pq.push({0,0});   
        // E
        while(!pq.empty())
        {
            // log E for pq
            auto it =pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            
            if(visited[node]) continue;
            // here we add in mst node and the parent
            visited[node]=1;
            sum+=wt;
            // eloge
            for(auto i : adj[node])
            {
                int adjNode=i[0];
                int edgeWt=i[1];
                if(!visited[adjNode])
                {
                    pq.push({edgeWt,adjNode});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends