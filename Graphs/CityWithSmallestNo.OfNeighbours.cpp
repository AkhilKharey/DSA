class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        for(auto it :edges)
        {
            // bidirectional graph
            cost[it[0]][it[1]]=it[2];
            cost[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)
        cost[i][i]=0;
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }
        int cntcity=n;
        int cityNo=-1;
        for(int city=0;city<n;city++)
        {
            int cnt=0;
            for(int adjCity=0;adjCity<n;adjCity++)
            {
                if(cost[city][adjCity]<=distanceThreshold)
                cnt++;
            }
            if(cnt<=cntcity)
            {
                cntcity=cnt;
                cityNo=city;
            }
        }
        return cityNo;
    }
};