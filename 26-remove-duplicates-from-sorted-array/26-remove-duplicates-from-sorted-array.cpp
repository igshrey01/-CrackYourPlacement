class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
        for(int i=1;i<n;i++){
            
            if(nums[ans]!=nums[i]){
                
                ans++;
                swap(nums[ans],nums[i]);
                
            }    
        }
        
        return ans+1;
    }
};