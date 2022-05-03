class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        //Brute Force - O(n^2)
//         int ans = 0;
        
//         for(int i=0;i<n;i++){
            
//             for(int j=i+1;j<n;j++)
//                 ans = max(ans,prices[j]-prices[i]);
            
//         }
//         return ans;
        
        
        //Optimized Approach
        //T.C - O(n)
        
        int minPrice = INT_MAX;
        int profit = 0;
        
        for(int i=0;i<n;i++){
            
            minPrice = min(minPrice,prices[i]);
            profit = max(profit , prices[i]-minPrice);
            
        }
        return profit;
    }
};