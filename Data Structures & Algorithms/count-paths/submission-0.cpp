class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        dp[m - 1][n - 1] = 1;

        for (int ix = m - 1; ix >= 0; ix--) {
            for(int jx = n - 1; jx >= 0; jx--) {
                dp[ix][jx] += dp[ix + 1][jx] + dp[ix][jx + 1];
            }
        }
        return dp[0][0];
    }
};
