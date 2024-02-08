/*
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return INT_MAX;
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j];

        int up = (i == 0) ? INT_MAX : grid[i][j] + func(i-1, j, grid, dp);
        int left = (j == 0) ? INT_MAX : grid[i][j] + func(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m-1, n-1, grid, dp);
    }
};
*/

class Solution {
public:

    
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // Initialize dp with INT_MAX
        dp[0][0] = grid[0][0]; // Set the starting cell

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) // Skip the first cell since it's already initialized
                    continue;
                
                int up = INT_MAX; // Initialize to INT_MAX
                int left = INT_MAX; // Initialize to INT_MAX

                if(i > 0)
                    up = grid[i][j] + dp[i - 1][j]; // Calculate the value from the cell above

                if(j > 0)
                    left = grid[i][j] + dp[i][j - 1]; // Calculate the value from the cell to the left
                
                // Update dp with the minimum value from up or left
                dp[i][j] = min(up, left);
            }                
        }
        return dp[m - 1][n - 1];
    }
};
