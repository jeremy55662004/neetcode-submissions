class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // res is initialized to [1, 1, 1, 1]
        vector<int> res(n, 1);

        for (int ix = 1; ix < n; ix++) {
            res[ix] = res[ix - 1] * nums[ix - 1];
        }

        int postfix = 1; // Initializes 'postfix' product to 1
        for (int i = n - 1; i >= 0; i--) { // Loop from i = n-1 (last index) down to 0
            res[i] *= postfix;   // Multiplies the current res[i] (which holds the prefix product) by the 'postfix' product
            postfix *= nums[i];  // Updates 'postfix' by multiplying it with the current number, preparing for the next iteration
        }
        return res;
    }
};
