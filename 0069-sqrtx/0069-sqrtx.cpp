class Solution {
public:
    int mySqrt(int x) {
        double pivot = INT32_MAX / 2;

        for (int i = 0; i < 500; i++) {
            pivot = (pivot + (double) x / pivot) / 2;
        }

        return (int) pivot;
    }
};
