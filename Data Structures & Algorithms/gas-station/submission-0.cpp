class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
                return -1;
        }

        int total = 0;
        int res = 0;
        for (int ix = 0; ix < gas.size(); ix++) {
            total += (gas[ix] - cost[ix]);

            if (total < 0) {
                total = 0;
                res = ix + 1;
            }
        }
        return res;
    }
};
