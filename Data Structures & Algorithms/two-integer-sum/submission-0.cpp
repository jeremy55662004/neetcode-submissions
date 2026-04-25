class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        int ix, complement;

        for (ix = 0; ix < nums.size(); ix++) {
            complement = target - nums[ix];
            if (map.find(complement) != map.end() ) {
                result.push_back(map[complement]);
                result.push_back(ix);
            }
            map[nums[ix]] = ix;
        }   
        return result; 
    }
};
