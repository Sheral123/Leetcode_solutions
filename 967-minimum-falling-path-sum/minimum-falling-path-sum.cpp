class Solution {
public:
    int func(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i == n-1) return dp[i][j] = matrix[i][j];
        if(dp[i][j]!= INT_MAX) return dp[i][j];

        int down = matrix[i][j] + func(i+1,j,n,matrix,dp);
        int dleft = (j > 0) ? matrix[i][j] + func( i + 1, j - 1,n,matrix, dp) : INT_MAX;
        int dright = (j < n - 1) ? matrix[i][j] + func( i + 1, j + 1,n,matrix, dp) : INT_MAX;
        int aa =  min(dleft,dright);
        return dp[i][j]=min(aa,down);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int minSum = INT_MAX;
        for(int j=0; j<n; j++){
            int ans = func(0,j,n,matrix,dp);
            minSum = min(minSum, ans);
        }
        return minSum;
    }
};
