
class Solution {
public:
    int nthUglyNumber(int n) {
        int DP[n];
        DP[0] = 1;
        // 1 2 3 4 5 6
        // n2 = 8
        // n3 = 6
        // n5 = 10
        // i2: 2 next2: 8
        // i3: 2 next3: 9
        // i5: 1 next5: 10
        int nextIdxOfTwo, nextIdxOfThree, nextIdxOfFive;
        nextIdxOfTwo = nextIdxOfThree = nextIdxOfFive = 0;

        int candidateOfMultipleOfTwo, candidateOfMultipleOfThree, candidateOfMultipleOfFive;
        candidateOfMultipleOfTwo = 2;
        candidateOfMultipleOfThree = 3;
        candidateOfMultipleOfFive = 5;

        int i = 1;
        for (; i < n; i++) {
            DP[i] = min(candidateOfMultipleOfTwo, min(candidateOfMultipleOfThree, candidateOfMultipleOfFive));
            if (DP[i] == candidateOfMultipleOfTwo) {
                nextIdxOfTwo++;
                candidateOfMultipleOfTwo = DP[nextIdxOfTwo] * 2;
            }
            if (DP[i] == candidateOfMultipleOfThree) {
                nextIdxOfThree++;
                candidateOfMultipleOfThree = DP[nextIdxOfThree] * 3;
            }
            if(DP[i] == candidateOfMultipleOfFive) {
                nextIdxOfFive++;
                candidateOfMultipleOfFive = DP[nextIdxOfFive] * 5;
            }
        }

        return DP[n-1];
    }
};