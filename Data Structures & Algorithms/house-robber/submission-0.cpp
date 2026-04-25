class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int ix = 2; ix < nums.size(); ix++) {
            dp[ix] = max(dp[ix - 1], dp[ix - 2] + nums[ix]);
        }

        return dp[nums.size() - 1];
    }
};
