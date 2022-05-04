class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> um;
        um[0]=1;
        int res = 0;
        int summ = 0;
        
        for(int i=0;i<n;i++){
            
            summ+=nums[i];
            if(um.find(summ-k)!=um.end())
            {
                res += um[summ-k];
            }
            
            um[summ]++;
            
        }
        return res;
    }
};