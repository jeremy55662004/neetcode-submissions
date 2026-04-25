class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int ix = n - 1; ix >= 0; ix--) {
            for (int jx = ix; jx < n; jx++) {
                //s[i+1...j-1]
                // j - i <= 2 for string length = 2
                if (s[ix] == s[jx] && 
                    (jx - ix <= 2 || dp[ix + 1][jx - 1])) {
                    dp[ix][jx] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
