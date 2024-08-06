class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0, rsum=0,maxSum=0,n=cardPoints.size();
        for(int i=0; i<k;i++){
            lsum = lsum + cardPoints[i];
        }
        maxSum = lsum;
        if(k == n) return lsum;
        int rind = n-1;
        for(int i = k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rind];
            rind--; 
            maxSum= max(maxSum,lsum + rsum);
        }
        return maxSum;
        
    }
};