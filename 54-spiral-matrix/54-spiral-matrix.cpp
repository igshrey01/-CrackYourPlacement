class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int minI = 0, minJ = 0, maxI = m-1, maxJ = n-1;
        vector<int> res;
        int cnt = 0;
        int totalEle = m*n;
        while(cnt<totalEle){
            
            for(int i = minJ;i<=maxJ && cnt<totalEle;i++){
                res.push_back(matrix[minI][i]);
                cnt++;
            }
            
            minI++;
            
            for(int j = minI; j<=maxI && cnt<totalEle;j++){
                res.push_back(matrix[j][maxJ]);
                cnt++;
            }
            
            maxJ--;
            
            for(int i = maxJ;i>=minJ && cnt<totalEle;i--){
                res.push_back(matrix[maxI][i]);
                cnt++;
            }
            
            maxI--;
            
            for(int j = maxI;j>=minI && cnt<totalEle;j--){
                res.push_back(matrix[j][minJ]);
                cnt++;
            }
            
            minJ++;
            
        }
        
        return res;
    }
};