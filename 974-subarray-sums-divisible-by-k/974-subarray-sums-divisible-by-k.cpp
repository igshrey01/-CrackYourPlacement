class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     
        int n = nums.size();
        int res = 0;
        unordered_map<int,int> um;
        int subSum = 0;
        um[0]=1;
        for(int i=0;i<n;i++){
            subSum+=nums[i];
            int val = subSum%k;
            if(val<0){
                val = k+val;
            }
            if(um.find(val)!=um.end()){
                res+=um[val];
            }
            um[val]++;
        }
        return res;
        
    }
};