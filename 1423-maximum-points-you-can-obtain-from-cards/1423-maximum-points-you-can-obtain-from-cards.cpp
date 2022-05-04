class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        vector<int> left(n),right(n);
        left[0] = cardPoints[0];
        right[n-1] = cardPoints[n-1];
        
        for(int i=1;i<n;i++)
            left[i] = left[i-1]+cardPoints[i];
        
        for(int j=n-2;j>=0;j--)
            right[j] = right[j+1]+cardPoints[j];
        
        int maxx = max(left[k-1],right[n-k]);
        
        for(int kk = 1;kk<k;kk++)
        {
            maxx = max(maxx,left[kk-1]+right[n-k+kk]);
        }
        
        return maxx;
        
    }
};