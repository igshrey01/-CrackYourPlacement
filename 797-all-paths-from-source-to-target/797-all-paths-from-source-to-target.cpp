class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &res,int n,int i,vector<int> &temp){
        
        temp.push_back(i);
        if(i==n)
            res.push_back(temp);
        
        for(auto x:graph[i]){
            dfs(graph,res,n,x,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> temp;
        int n = graph.size();
        
        dfs(graph,res,n-1,0,temp);
        return res;
    }
};