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
        int N = m + n - 2;
        int r = m-1;
        double ans = 1;
        for(int i=1; i<=r; i++){
            ans = ans*(N - r + i)/i;
        }
        return ans;
    }  

};

