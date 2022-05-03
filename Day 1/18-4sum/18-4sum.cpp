class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int low  = j+1, high = n-1;
                
                while(low<high){
                    
                    long long val = (long long)nums[i]+(long long)nums[j]+(long long)nums[low]+(long long)nums[high];
                    
                    if(target>val)
                        low++;
                    
                    else if(target<val)
                        high--;
                    
                    else{
                        
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[low]);
                        quad.push_back(nums[high]);
                        res.push_back(quad);
                        
                        while(low<high && nums[low]==quad[2])
                            low++;
                        
                        while(low<high && nums[high]==quad[3])
                            high--;
                        
                    }
                        
                }
                
                while(j+1<n && nums[j]==nums[j+1])
                    j++;
                
            }
            
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            
        }
        return res;
    }
};