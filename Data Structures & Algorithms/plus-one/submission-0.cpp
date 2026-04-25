class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int ix = n - 1; ix >= 0; ix--) {
            if (digits[ix] < 9) {
                digits[ix]++;
                return digits;
            }
            digits[ix] = 0;
        }
        //[9, 9, 9] → [0, 0, 0] → add a leading 1 → [1, 0, 0, 0]
        vector<int> result(n + 1);
        result[0] = 1;
        return result;
    }
};
