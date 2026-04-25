class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int ix = 0; ix < nums.size(); ix++) {
            if (nums[ix] > 0) break;
            if (ix > 0 && nums[ix] == nums[ix - 1]) {
                continue;
            }
            int l = ix + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[ix] + nums[l] + nums[r];

                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[ix], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        } 
        return res;
    }
};
