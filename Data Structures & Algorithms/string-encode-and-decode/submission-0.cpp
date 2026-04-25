class Solution {
public:

    string encode(vector<string>& strs) {
        /* Ex: 4#lint4#code4#love3#you */
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int ix = 0;
        while (ix < s.size()) {
            int jx = ix;
            while (s[jx] != '#') {
                jx++;
            }

            // Example: If i=0, j=1, it extracts s[0] with length 1. If s[0] is '4', then "4" is the length string.
            int length = stoi(s.substr(ix, jx - ix));

            // Update index 'i', skipping over the length string and the '#' delimiter.
            ix = jx + 1;

            // Calculate the ending position for the original string.
            jx = ix + length;

            // s.substr(i, length) extracts a substring starting at the current 'i' position with 'length'.
            res.push_back(s.substr(ix, length));

            // Update index 'i' again, preparing for the decoding of the next string.
            ix = jx;
        }
        return res;
    }
};
