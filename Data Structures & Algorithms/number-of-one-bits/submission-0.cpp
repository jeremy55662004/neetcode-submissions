class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int ix = 0; ix < 32; ix++) {
            if ((1 << ix) & n) {
                res++;
            }
        }
        return res;
    }
};
