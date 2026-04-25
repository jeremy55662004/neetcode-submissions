class Solution {
public:
    bool isAnagram(string s, string t) {
        int ix;

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (ix = 0; ix < s.length(); ix++) {
            countS[s[ix]]++;
            countT[t[ix]]++;
        }
        return countS == countT;
    }
};
