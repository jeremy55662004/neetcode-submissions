class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // res is initialized to [1, 1, 1, 1]
        vector<int> res(n, 1);

        for (int ix = 1; ix < n; ix++) {
            res[ix] = res[ix - 1] * nums[ix - 1];
        }

        int postfix = 1;
        for (int ix = n - 1; ix >= 0; ix--) {
            res[ix] *= postfix;
            postfix *= nums[ix];
        }
        return res;
    }
};
