class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = nums[0];
        int max_end_here = nums[0];
        int min_end_here = nums[0];

        for (int ix = 1; ix < nums.size(); ix++) {
            int current_num = nums[ix];
            int prev_max_end_here = max_end_here;

            max_end_here = max({current_num, 
                                current_num * prev_max_end_here, 
                                current_num * min_end_here});

            min_end_here = min({current_num, 
                                current_num * prev_max_end_here, 
                                current_num * min_end_here});

            result = max(result, max_end_here);
        }
        
        return result;
    }
};
