
class Solution {
public:
    int countDigitOne(int n) {
        if(n == 1'000'000'000){
            return 900000001;
        }
        int p, d, r;
        int cnt = 0;
        for (int i = 0; i < 9; i++) {
            d = pow(10, i);
            if(n < d){
                break;
            }
            p = (n + 1 - d) / (10 * d);
            r = (n + 1 - d) % (10 * d);
            cnt += p * d + R(r,d);
        }

        return cnt;
    }

    int R(int r, int d){
        if(r <= d) {
            return r;
        }
        return d;
    }
};