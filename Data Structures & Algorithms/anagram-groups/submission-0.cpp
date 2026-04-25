class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       /* Example: {
    "1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0": ["eat", "tea", "ate"],
    "1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0": ["tan", "nat"],
    "1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0": ["bat"]
} */
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0); // Twenty-six zeros
            for (char c : s) {
                count[c - 'a']++;
            }
            // the count of the letter 'a', which is then converted into a string and stored in the key variable.
            string key = to_string(count[0]);
            for (int ix = 1; ix < 26; ix++) {
                key += ',' + to_string(count[ix]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto & pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
