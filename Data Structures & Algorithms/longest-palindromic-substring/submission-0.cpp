class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int ix = n - 1; ix >= 0; ix--) {
            for (int jx = ix; jx < n; jx++) {
                // length = 1,2,3 then it's always true
                // or length dp[i+1 ~ j-1] is true
                // then set dp[i ~ j] to true
                if (s[ix] == s[jx] && (jx - ix <= 2 || dp[ix + 1][jx - 1])) {
                    dp[ix][jx] = true;
                    if (resLen < (jx - ix + 1)) {
                        resIdx = ix;
                        resLen = jx - ix + 1;
                    }
                }
            }
        }
        return s.substr(resIdx, resLen);
    }
};
