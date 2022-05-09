// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleBFS(int n, vector<int> adj[], vector<bool> &visited){
        
        queue<pair<int,int>> q;
        q.push({n,-1});
        visited[n] = true;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int par = curr.second;
            
            for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push({x,node});
                }
                else if(par!=x){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycleDFS(int n,vector<int> adj[],vector<bool> &visited,int par){
        
        visited[n] = true;
        for(auto x:adj[n]){
            if(!visited[x]){
                if(cycleDFS(x,adj,visited,n))
                    return true;
            }
            else if(par!=x){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++){
            if(visited[i])
                continue;
                
            if(cycleDFS(i,adj,visited,-1))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends