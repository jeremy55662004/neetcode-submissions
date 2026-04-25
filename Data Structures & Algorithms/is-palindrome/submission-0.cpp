class Solution {
public:
    bool is_alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            /* To check if alphanumeric characters */
            while (l < r && !is_alphaNum(s[l])) {
                l++;
            }
            while (r > l && !is_alphaNum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
