class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = nums[0];
        rightMax[n-1] = nums[n - 1];

        for (int ix = 1; ix < n; ix++) {
            if (ix % k == 0) {
                leftMax[ix] = nums[ix];
            } else {
                leftMax[ix] = max(leftMax[ix - 1], nums[ix]);
            }

            if ((n - 1 - ix) % k == 0) {
                rightMax[n - 1 - ix] = nums[n - 1 - ix];
            } else {
                rightMax[n - 1 - ix] = max(rightMax[n - ix], nums[n - 1 - ix]);
            }
        }

        vector<int> output(n - k + 1);

        for (int ix = 0; ix < n - k +1; ix++) {
            output[ix] = max(leftMax[ix + k - 1], rightMax[ix]);
        }

        return output;
    }
};
