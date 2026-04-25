class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)  {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int ix = 3; ix <= n; ix++) {
            dp[ix] = dp[ix - 1] + dp[ix -2];
        }
        return dp[n];
    }
};
