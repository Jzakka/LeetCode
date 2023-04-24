class Solution {
public:
    bool isUgly(int n) {
        while (isMultipleOfTwoThreeFive(n)) {
            n /= getDivisor(n);
        }
        return n == 1;
    }

    bool isMultipleOfTwoThreeFive(int n){
        return n && (!(n % 2) || !(n % 3) || !(n % 5));
    }

    int getDivisor(int n){
        if(!(n&1)) {
            return 2;
        } else if (!(n % 3)) {
            return 3;
        } else if (!(n % 5)) {
            return 5;
        }
        return -1;
    }
};