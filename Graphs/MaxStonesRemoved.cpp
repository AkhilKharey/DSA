
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
    int removeStones(vector<vector<int>>& stones) {
        // first we need to know the row and column size of our matrix as it is not given
        int n=stones.size();
        int row=0;
        int col=0;
        for(auto it:stones)
        {
            row=max(row,it[0]);
            col=max(col,it[1]);
        }
        DisjointSet ds(row+col+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones)
        {
            int nodeRow=it[0];
            int nodeCol=it[1]+row+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
           
        }
        int cnt=0;
        for(auto it:stoneNodes)
        {
            if(ds.findUParent(it.first)==it.first)
            {
                cnt++;
            }
        }
        return n-cnt;
    }
};