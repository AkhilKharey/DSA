
class DisjointSet{
    public:
    vector<int>rank,parent,size;
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
 private:
     bool isValid(int row,int col,int size)
     {
        return (row>=0 && row<size && col>=0 && col<size);
     }
public:
    int largestIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       DisjointSet ds(n*n);
    //    step 1 is to make the connections
        int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
       for(int row=0;row<n;row++){
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==0) continue;
           
            for(int ind=0;ind<4;ind++)
            {
                int newr=row+delrow[ind];
                int newc=col+delcol[ind];
                if(isValid(newr,newc,n) && grid[newr][newc]==1)
                {
                    int nodeNo=row*n+col;
                    int adjNodeNo=newr*n+newc;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
       } 
    //    step 2 is to convert 0's to 1's one by one and see what maximum size we can get
    int mx=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==1) continue;
            set<int>components;
            for(int ind=0;ind<4;ind++)
            {
                int newr=row+delrow[ind];
                int newc=col+delcol[ind];
                if(isValid(newr,newc,n) && grid[newr][newc]==1)
                components.insert(ds.findUParent(newr*n+newc));
            }
            // considering the 0 which we are changing
            int sizeTotal=1; 
            for(auto it:components)
            {
                sizeTotal+=ds.size[it];
            }
            mx=max(mx,sizeTotal);
        }
    }
    // what if all the cells are 1 then the answer would be wrong
    for(int cellNo=0;cellNo<n*n;cellNo++)
    {
        mx=max(mx,ds.size[ds.findUParent(cellNo)]);
    }
    return mx;
    }
};