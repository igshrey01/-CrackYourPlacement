class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int cnt = 0;
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto x:rooms[node]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        if(cnt == n)
            return true;
        return false;
    }
};