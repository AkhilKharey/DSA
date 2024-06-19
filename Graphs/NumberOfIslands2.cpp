//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node)
    {
     if(node==parent[node])
     return node;
     return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds( n*m ) ;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        vector<int>ans;
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col])
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            // phle badha lete hai bad me kisi se connect ho rha hoga to cnt kam kr denge
            cnt++;
            int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
            for(int ind=0;ind<4;ind++)
            {
                int adjr=row+delrow[ind];
                int adjc=col+delcol[ind];
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m)
                {
                    if(vis[adjr][adjc])
                    {
                        int nodeno=row*m+col;
                        int adjnodeno=adjr*m+adjc;
                        if(ds.findUParent(nodeno)!=ds.findUParent(adjnodeno))
                        {
                            // if not already connected
                            cnt--;
                            ds.unionBySize(nodeno,adjnodeno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends