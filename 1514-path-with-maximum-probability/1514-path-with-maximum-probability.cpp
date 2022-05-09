class Solution {
public:
    double dijkstraAlgo(int n, vector<pair<int,double>> adj[], int start, int end){
        
        vector<double> prob(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        prob[start] = 1;
        
        while(!pq.empty()){
            
            auto prev = pq.top().second;
            auto prevProb = pq.top().first;
            pq.pop();
            
            for(auto it:adj[prev]){
                
                auto curr = it.first;
                auto currProb = it.second;
                
                if(prob[prev]*currProb>prob[curr]){
                    prob[curr] = prob[prev]*currProb;
                    pq.push({prob[curr],curr});
                }
                
            }
            
        }
        
        return prob[end];
        
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        int ne = edges.size();
        
        for(int i=0;i<ne;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        return dijkstraAlgo(n,adj,start,end);
        
    }
};