class Solution {
public:
    int climbStairs(int n) {
        int way_to_prev_step = 1;
        int way_to_curr_step = 1;
        int new_ways = 0;

        for (int ix = 0; ix < n-1; ix++) {
            new_ways = way_to_prev_step + way_to_curr_step;
            way_to_prev_step = way_to_curr_step;
            way_to_curr_step = new_ways;
        }

        return way_to_curr_step;
    }
};
