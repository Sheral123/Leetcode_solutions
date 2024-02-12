/*class Solution {
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
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        // Fill the last row of dp with values from the last row of the matrix
        for(int j = 0; j < n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + dp[i + 1][j];
                int leftup = (j > 0) ? matrix[i][j] + dp[i + 1][j - 1] : INT_MAX;
                int rightup = (j < n - 1) ? matrix[i][j] + dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = min(up, min(leftup, rightup));
            }
        }

        // Find the minimum sum from the first row of dp
        int minSum = INT_MAX;
        for(int j = 0; j < n; j++){
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
