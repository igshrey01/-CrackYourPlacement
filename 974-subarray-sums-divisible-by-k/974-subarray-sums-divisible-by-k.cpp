class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     
        int n = nums.size();
        
        int res = 0;
        unordered_map<int,int> um;
        um[0]=1;
        
        int subSum = 0;
        
        for(int i=0;i<n;i++){
            
            subSum+=nums[i];
            int mod = subSum%k;
            
            if(mod<0)
                mod = k+mod;
            
            if(um.find(mod)!=um.end())
                res+=um[mod];
            
            um[mod]++;
            
        }
        return res;
        
    }
};