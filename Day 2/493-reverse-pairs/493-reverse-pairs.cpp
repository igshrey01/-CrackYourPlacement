class Solution {
public:
    
    int merge(vector<int> &nums, int left, int mid, int right, vector<int> &temp){
        
        long long ans = 0;
        
        int j = mid;
        for(int i=left;i<mid;i++){
            
            while(j<=right && nums[i] > 2*(long long) nums[j])
                j++;
            
            ans+=j-mid;
            
        }
        
        int i = left, k = left;
        j = mid;
        
        while(i<mid && j<=right){
        
            if(nums[i]<nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
            
        }
        while(i<mid)
            temp[k++] = nums[i++];
        
        while(j<=right)
            temp[k++] = nums[j++];
        
        for(int i=left;i<=right;i++)
            nums[i] = temp[i];
        
        
        return ans;
    }
    
    int mergeSort(vector<int> &nums, int left, int right, vector<int> &temp){
        
        long long ans = 0;
        
        if(left<right){
            
            int mid = left+(right-left)/2;
            ans+=mergeSort(nums,left,mid,temp);
            ans+=mergeSort(nums,mid+1,right,temp);
            ans+=merge(nums,left,mid+1,right,temp);
            
        }
        
        return ans;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums,0,n-1,temp);
        
    }
};