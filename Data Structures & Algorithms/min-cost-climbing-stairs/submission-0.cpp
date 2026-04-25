class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int ix = 2; ix < n; ix++) {
            dp[ix] = cost[ix] + min(dp[ix - 1], dp[ix - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
