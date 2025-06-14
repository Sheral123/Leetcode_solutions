class Solution {
public:


    void bfs(int row, int col, vector<vector<int>> &visGrid, vector<vector<char>>& grid){
        visGrid[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == '1' && !visGrid[nrow][ncol]){
                    visGrid[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visGrid(n, vector<int>(m,0));
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visGrid[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, visGrid, grid);
                }
            }
        }
        return cnt;
    }
};