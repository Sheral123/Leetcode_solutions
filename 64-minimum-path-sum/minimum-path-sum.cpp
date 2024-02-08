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
/*
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int>(n, -1)); 
        vector<int> prev(n, 0); 
        
        prev[0] = grid[0][0];  

        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0); 
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)  
                    continue;
                
                int up = INT_MAX;  
                int left = INT_MAX;  

                if(i > 0)
                    up = grid[i][j] + prev[j];  

                if(j > 0)
                    left = grid[i][j] + temp[j-1];  
                
                 
                temp[j] = min(up, left);
            }     
            prev = temp;           
        }

        return prev[n-1];
    }
};*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<int> prev(m,0);
        for(int i=0; i<n; i++){
            vector<int> temp(m,0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    temp[0] = grid[0][0];
                }
                else{
                    int up = grid[i][j]; 
                    if(i>0) up+= prev[j];
                    else up+= 1e9;

                    int left = grid[i][j];
                    if(j>0) left+= temp[j-1];
                    else left+= 1e9;

                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }
};

