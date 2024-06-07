class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int V=numCourses;
       vector<int>indegree(V,0);
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
       if(topo.size()<numCourses)
       return false;
       else
       return true;
    }
};