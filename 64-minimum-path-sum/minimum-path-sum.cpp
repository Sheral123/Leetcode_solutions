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
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i > 0)
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
class Solution {
public:

    int minSumPath(vector<vector<int>> &grid) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // Initialize a DP table to store minimum path sums

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else {
                // Calculate the minimum path sum considering moving up and moving left
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i - 1][j]; // Include the minimum path sum from above
                    else
                     up += 1e9; // A large value if moving up is not possible (out of bounds)

                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j - 1]; // Include the minimum path sum from the left
                    else
                        left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[m - 1][n - 1];
}
   
};
*/
