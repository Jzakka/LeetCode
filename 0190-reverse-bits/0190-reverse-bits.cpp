
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits;
        for (int i = 0; i < 32; i++) {
            bits[i] = (n >> i) & 1;
        }
        uint32_t res = 0;
        for (int i = 0; i < 31; i++) {
            res += bits[i];
            res <<= 1;
        }
        res += bits[31];
        return res;
    }
};
