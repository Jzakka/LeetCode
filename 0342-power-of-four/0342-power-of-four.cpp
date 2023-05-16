class Solution {
public:
    bool isPowerOfFour(int n) {
        double logged2 = log2(n);

        if (logged2 - floor(logged2) > 0) {
            return false;
        }

        return !isinf(logged2) && !isnan(logged2) && !(((int) logged2) & 1);
    }
};