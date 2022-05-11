class Solution {
public:
    vector<int> topoSort(vector<int> adj[],int n){
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        int cnt = 0;
        while(!q.empty()){
            
            auto node = q.front();
            cnt++;
            res.push_back(node);
            q.pop();
            
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(cnt==n)
            return res;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> adj[numCourses];
        int np = pre.size();
        for(int i=0;i<np;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        
        return topoSort(adj,numCourses);
    }
};