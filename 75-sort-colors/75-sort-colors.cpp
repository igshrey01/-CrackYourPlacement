class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute Force - O(nlogn)
        //Simple Merge Sort
        
        //1st Optimized Approach
        //T.C = O(n)
        //2 N iterations
//         int cnt0 = 0, cnt1=0, cnt2=0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]==0)
//                 cnt0++;
//             else if(nums[i]==1)
//                 cnt1++;
//             else
//                 cnt2++;
//         }
        
//         for(int i=0;i<n;i++){
//             if(cnt0){
//                 cnt0--;
//                 nums[i]=0;
//             }
//             else if(cnt1){
//                 cnt1--;
//                 nums[i]=1;
//             }
//             else{
//                 cnt2--;
//                 nums[i]=2;
//             }
//         }
        
        //Best Approach 
        //T.C - O(n)
        
        int n = nums.size();
        int low = 0, mid=0, high = n-1;
        
        while(mid<=high){
            
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            
            else if(nums[mid]==1)
                mid++;
            
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};