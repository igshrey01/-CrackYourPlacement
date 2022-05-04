class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> um;
        int res = 0;
        
        for(int i=0;i<n;i++){
            
            if(um.find(k-nums[i])!=um.end()){
                if(um[k-nums[i]]!=0)
                {
                    um[k-nums[i]]--;
                    res++;
                }
                else
                    um[nums[i]]++;
                
            }
            else{
                um[nums[i]]++;
            }
            
            
        }
        return res;
    }
};