class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for (int ix = 1; ix <= n; ix++) {
            //(ix & 1) equals to (ix % 2);
            dp[ix] = dp[ix >> 1] + (ix & 1);
        }
        return dp;
    }
};
