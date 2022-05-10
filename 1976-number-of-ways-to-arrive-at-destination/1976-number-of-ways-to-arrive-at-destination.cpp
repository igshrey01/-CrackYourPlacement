class Solution {
    
public:
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        int nr = roads.size();
        for(int i=0;i<nr;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        int mod = (1e9+7);
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>> >pq;
        vector<long long> dis(n,1e18);
        vector<long long> way(n,0);
        dis[0] = 0;
        way[0] = 1;
        pq.push({0,0});
        vector<bool> visited(n,false);
        
        while(!pq.empty()){
            
            auto prev = pq.top().second;
            auto prevDis = pq.top().first;
            pq.pop();
            if(visited[prev])
                continue;
            visited[prev] = true;
            
            for(auto x:adj[prev]){
                auto curr = x.first;
                auto currDis = x.second;
                if(dis[prev]+currDis<dis[curr]){
                    
                    dis[curr] = dis[prev]+currDis;
                    pq.push({dis[curr],curr});
                    way[curr] = way[prev];
                    
                    
                }
                else if(dis[prev]+currDis == dis[curr]){
                    way[curr] = (way[curr]+way[prev])%mod;
                }
            }
            
        }
        
        
        return way[n-1];
        
    }
};