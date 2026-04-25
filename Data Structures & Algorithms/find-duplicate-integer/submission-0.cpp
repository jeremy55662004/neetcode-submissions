class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            // -1 means for index of array start from 0
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};
