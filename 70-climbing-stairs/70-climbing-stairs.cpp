class Solution {
public:
    int recursion(int n,vector<int> &dp){
        if(n<=2)
            return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=recursion(n-2,dp)+recursion(n-1,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);
    }
};