class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long cnt = (long)right - left + 1;
        long res = left&right;
        long x = 1;
        for (unsigned i = 0; i < 32; i++, x <<= 1) {
            if (x >= cnt) {
                break;
            }
        }
        res &= -x;

        return res;
    }
};