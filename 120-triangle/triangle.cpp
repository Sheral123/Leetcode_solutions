class Solution {
public:
/*
    int func(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp ){
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + func(i+1,j,n,triangle,dp);
        int diagonal = triangle[i][j] + func(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(down, diagonal);
    }
*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n,0);
        vector<int> prev(n,0);

        for(int j=0 ; j<n; j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0 ; i--){
            for(int j=i ; j>=0; j--){
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];
                dp[j] = min(down,diagonal);
            }
            prev=dp;
        }
        return prev[0];
    }
};