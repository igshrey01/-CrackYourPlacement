class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxx = nums[0];
        if(maxx==0 && n>=2){
            return false;
        }
        
        for(int i=1;i<n-1;i++){
            
            maxx--;
            maxx = max(maxx,nums[i]);
            if(maxx<=0){
                return false;
            }
            
        }
        return maxx>=0;
        
    }
};