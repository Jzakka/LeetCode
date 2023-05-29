class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int uN = 9 * P(9, n-1);
        return uN + countNumbersWithUniqueDigits(n - 1);
    }

    int P(int num, int count){
        int mul = 1;
        for (int i = 0; i < count; i++) {
            mul *= num--;
        }
        return mul;
    }
};