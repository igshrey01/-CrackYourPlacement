// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool topoSort(vector<int> adj[],int n){
        
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
            return true;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    
	    vector<int> adj[N];
        int np = pre.size();
        for(int i=0;i<np;i++){
            adj[pre[i].second].push_back(pre[i].first);
        }
        
        
        return topoSort(adj,N);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends