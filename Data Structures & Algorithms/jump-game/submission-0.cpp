class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int ix = nums.size() - 2; ix >= 0; ix--) {
            if (ix + nums[ix] >= goal) {
                goal = ix;
            }
        }
        return goal == 0;
    }
};
