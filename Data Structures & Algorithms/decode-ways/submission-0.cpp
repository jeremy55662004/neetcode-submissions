class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;

        for (int ix = s.size() - 1; ix >= 0; ix--) {
            if (s[ix] == '0') {
                dp[ix] = 0;
            } else {
                //For (s[i])
                dp[ix] = dp[ix + 1];
                //For (s[i]s[i+1])
                if (ix + 1 < s.size() && (s[ix] == '1' || 
                    s[ix] == '2' && s[ix + 1] < '7')) {
                    dp[ix] = dp[ix + 1] + dp[ix + 2];
                }
            }
        }
        return dp[0];
    }
};
