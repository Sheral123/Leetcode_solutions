/*class Solution {
public:
    int func(int i, int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i ==0 && j==0) return dp[i][j] = 1;
        return dp[i][j] = func(i-1, j, obstacleGrid, dp) + func(i, j-1, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1, n-1, obstacleGrid, dp);
    }
};
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0);
        if(obstacleGrid[0][0]) return 0;

        for(int i=0; i<m ; i++){
            vector<int> temp(n,0);
            for(int j=0 ; j<n; j++){
                if(obstacleGrid[i][j] != 1){
                    int up = 0;
                    int left = 0;
                    
                    if(i>0){
                        up = prev[j];
                    }
                    if(j>0){
                        left = temp[j-1];
                    }
                    if(i == 0 && j == 0) temp[0] = 1;
                    else temp[j] = up + left;
                }

            }
            prev=temp;
        }
        return prev[n-1];
    }
};