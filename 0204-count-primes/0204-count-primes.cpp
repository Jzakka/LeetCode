class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }
        bitset<5000001> bits;
        bits.flip();
        bits.flip(0);
        bits.flip(0);
//        vector<bool> table(n, true);
//        table.at(0) = false;
//        table.at(1) = false;

        int cnt = 0;
        long i;
        for (i = 2; i*i < n; i++) {
            if (bits.test(i)) {
                cnt++;
                for (long j = i * i; j < n; j += i) {
                    bits.set(j, 0);
                }
            }
        }
        for (; i < n; i++) {
            if (bits.test(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};