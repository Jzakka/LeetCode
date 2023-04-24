
class Solution {
private:
    int DP[10001];
public:
    Solution(){
        for (int i = 0; i < 10001; i++) {
            DP[i] = -1;
        }
        for (int i = 0; i <= 100; i++) {
            DP[i*i] = 1;
        }
    }

    int numSquares(int n) {
        if(DP[n] != -1){
            return DP[n];
        }
        if (n == 0) {
            return 0;
        }

        int root = sqrt(n);

        int res = INT32_MAX;
        for (int i = root * root; i >= 1; i = prevSqNum(i)) {
            res = min(numSquares(n - i) + 1, res);
        }
        DP[n] = res;
        return res;
    }

    int prevSqNum(int sqNum){
        int num = sqrt(sqNum);
        int prevNum = num-1;
        return sqNum - (num + prevNum);
    }
};