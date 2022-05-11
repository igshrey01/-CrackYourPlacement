class Solution {
public:
    int dijkstra(vector<pair<int,int>> adj[],int n,int src){
        
        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dis[src] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int nodeDis = pq.top().first;
            pq.pop();
            
            for(auto x:adj[node]){
                
                int adjNode = x.first;
                int adjDis = x.second;
                
                if(nodeDis + adjDis < dis[adjNode]){
                    dis[adjNode] = nodeDis + adjDis;
                    pq.push({dis[adjNode],adjNode});
                }
            }
            
        }
        
        int maxx = -1;
        
        for(int i=1;i<=n;i++){
            
            if(dis[i]==INT_MAX){
                return -1;
            }
            maxx = max(maxx,dis[i]);
        }
        
        return maxx;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        int nt = times.size();
        vector<pair<int,int>> adj[n+1];
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        
        return dijkstra(adj,n,k);
    }
};