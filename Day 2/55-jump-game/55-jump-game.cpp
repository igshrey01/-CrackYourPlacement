class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxx = nums[0];
        
        for(int i=1;i<n;i++){
            
            if(maxx == 0)
                return false;
            maxx = max(maxx-1,nums[i]);
            
        }
        return true;
        
    }
};