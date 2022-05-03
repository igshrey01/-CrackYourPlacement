class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            
            int low = i+1,high = n-1;
            
            while(low<high){
                
                int val = nums[low]+nums[high]+nums[i];
                
                if(val<0)
                    low++;
                
                else if(val>0)
                    high--;
                
                else
                {
                    
                    vector<int> triple;
                    triple.push_back(nums[i]);
                    triple.push_back(nums[low]);
                    triple.push_back(nums[high]);
                    res.push_back(triple);
                    
                    while(low<high && nums[low]==triple[1])
                        low++;
                    
                    while(low<high && nums[high]==triple[2])
                        high--;
                    
                }
                    
            }
            
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            
        }
        return res;
    }
};