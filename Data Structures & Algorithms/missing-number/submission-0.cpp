class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for (int ix = 0; ix < n; ix++) {
            //Because a ^ a = 0
            xorr ^= ix ^ nums[ix];
        }
        return xorr;
    }
};
