/*class Solution {
public:
 
    int func(int i, int j,vector<vector<int>> &dp){
        if(i ==1 && j==1) return 1;
        if(i < 1 || j < 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int up = func(i-1, j, dp);
        int left = func(i, j-1, dp);
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return func(m,n,dp);
    }
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            vector<int> temp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    temp[j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (i > 1) {
                        up = cur[j];
                    }
                    if (j > 1) {
                        left = temp[j - 1];
                    }

                    temp[j] = up + left;
                }
            }
            cur = temp;
        }
        return cur[n];
    }
};

