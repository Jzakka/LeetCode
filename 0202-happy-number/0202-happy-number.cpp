
class Solution {
public:
    bool isHappy(int n) {
        for (int i = 0; i < 30; i++) {
            int sum = 0;
            int exp = 0;
            while (n) {
                sum += pow(n % (int) pow(10, exp + 1) / pow(10, exp),2);
                n /= 10;
            }
            if (sum == 1) {
                return true;
            }
            n = sum;
//            cout << n << "\n";
        }
        return false;
    }
};