class Solution {
public:
   
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        //Brute Force
        //T.C - O(n^2)
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(nums[slow]!=nums[fast]);
        
        fast = nums[0];
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};