// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclicDFS(int n, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited){
        
        visited[n] = true;
        dfsVisited[n] = true;
        
        for(auto x:adj[n]){
            if(!visited[x]){
                if(isCyclicDFS(x,adj,visited,dfsVisited)){
                    return true;
                }
            }
            else if(dfsVisited[x])
                return true;
        }
        dfsVisited[n] = false;
        return false;
    }
    bool kahnAlgo(int v, vector<int> adj[]){
	    
	    vector<int> res;
	    vector<int> indegree(v,0);
	    for(int i=0;i<v;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    
	    
	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto x:adj[node]){
	            indegree[x]--;
	            if(indegree[x]==0){
	                q.push(x);
	            }
	            
	        }
	    }
	    if(cnt==v){
	           return false;
	       }
	    return true;
	    
	}
    bool isCyclic(int V, vector<int> adj[]) {
        // vector<bool> visited(V,false);
        // vector<bool> dfsVisited(V,false);
        
        // for(int i=0;i<V;i++){
        //     if(isCyclicDFS(i,adj,visited,dfsVisited))
        //         return true;
        // }
        // return false;
        return kahnAlgo(V,adj);
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends