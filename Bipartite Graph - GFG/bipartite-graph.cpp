// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteComponent(int i, vector<int> adj[],vector<bool> &visited,vector<int> &color)
    {
        
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i] = true;
        color[i] = 0;
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int par = curr.second;
            int col = color[node];
            for(auto x:adj[node]){
                if(!visited[x]){
                    visited[x] = true;
                    color[x] = 1-col;
                    q.push({x,node});
                }
                else if(par!=x){
                    if(color[x]!=(1-col))
                    {
                        return false;
                    }
                }
            }
            
        }
        
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<bool> visited(V,false);
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        
	        if(visited[i])
	            continue;
	        
	        if(!isBipartiteComponent(i,adj,visited,color))
	        {
	            return false;
	        }
	        
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends