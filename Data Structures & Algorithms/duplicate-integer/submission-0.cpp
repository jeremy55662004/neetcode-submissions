class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /* Default value is 0 */
        unordered_map<int, int> map;
        int ix;

       for (ix = 0; ix < nums.size(); ix++) {
            map[nums[ix]]++;
            
            if (map[nums[ix]] > 1) {
                return true;
            }
        }
        return false;
    }
};
