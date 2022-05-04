class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 1;
        long long candEle = LLONG_MAX;
        
        for(int i=0;i<n;i++){
            
            if(candEle == nums[i])
                cnt++;
            else
                cnt--;
            
            if(cnt==0)
            {
                cnt = 1;
                candEle = nums[i];
            }
        
        }
        
        cnt = 0;
        for(int i=0;i<n;i++){
            
            if(candEle==nums[i])
                cnt++;
            
        }
        
        if(cnt>n/2)
            return candEle;
        return -1;
    }
};