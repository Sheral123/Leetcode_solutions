#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        int n = matrix.size();
        if (i == n - 1) return matrix[i][j];

        if (memo[i][j] != INT_MAX) return memo[i][j];

        int dleft = (j > 0) ? helper(matrix, i + 1, j - 1, memo) : INT_MAX;
        int ddown = helper(matrix, i + 1, j, memo);
        int dright = (j < n - 1) ? helper(matrix, i + 1, j + 1, memo) : INT_MAX;

        memo[i][j] = matrix[i][j] + min(ddown, min(dleft, dright));
        return memo[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        int minSum = INT_MAX;

        for (int j = 0; j < n; ++j)
            minSum = min(minSum, helper(matrix, 0, j, memo));

        return minSum;
    }


};
