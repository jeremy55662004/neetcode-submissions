class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int ix = 0; ix < 32; ix++) {
            uint32_t bit = (n >> ix) & 1;
            res += (bit << (31 - ix));
        }
        return res;
    }
};
