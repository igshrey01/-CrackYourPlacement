class Solution {
public:
   void combSum(vector<int> &candidates,int target,vector<int> &temp,int n,vector<vector<int>> &ans){
       if(target<0){
           return;
       }
       if(n==0){
           if(target == 0){
               ans.push_back(temp);
           }
           return;
       }
       combSum(candidates,target,temp,n-1,ans);
       if(target>=candidates[n-1]){
           temp.push_back(candidates[n-1]);
           combSum(candidates,target-candidates[n-1],temp,n,ans);
           temp.pop_back();
       }
       return;
       
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=candidates.size();
        combSum(candidates,target,temp,n,ans);
        return ans;
    }
};