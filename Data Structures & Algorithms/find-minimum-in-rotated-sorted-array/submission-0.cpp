class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) {
                //min number is on the left side
                r = m;
            } else {
                //min numbder is on the right side
                l = m + 1;
            }
        }
        return nums[l];
    }
};
