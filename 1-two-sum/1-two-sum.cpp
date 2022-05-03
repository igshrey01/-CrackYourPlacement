class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    { 
        
        vector<int> res;
        int n = nums.size();
        unordered_map<int,int> um;
        
        for(int i=0;i<n;i++){
            if(um.find(target-nums[i])!=um.end()){
                res.push_back(um[target-nums[i]]);
                res.push_back(i);
                break;
            }
            um[nums[i]]=i;
        }
        return res;
        
    }
};