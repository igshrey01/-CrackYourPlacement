class Solution {
public:
    bool isComponentBipartite(vector<vector<int>> &graph,vector<bool> &visited,int n,vector<int> &color){
        
        queue<pair<int,int>> q;
        visited[n] = true;
        color[n] = 0;
        q.push({n,-1});
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int par = curr.second;
            int col = color[node];
            for(auto x:graph[node]){
                
                if(!visited[x]){
                    color[x] = 1-col;
                    visited[x] = true;
                    q.push({x,node});
                }
                else if(par!=x){
                    if(color[x]!=(1-col))
                        return false;
                }
                
            }
            
        }
        
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            
            if(visited[i])
                continue;
            if(!isComponentBipartite(graph,visited,i,col)){
                return false;
            }
            
        }
    
        return true;
        
    }
};