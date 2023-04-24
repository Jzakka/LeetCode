class Solution {
public:
    public:
    int climbStairs(int n) {
        int DP[46];
        DP[1] = 1;
        DP[2] = 2;
        for (int i = 3; i <= n; i++) {
            DP[i] = DP[i - 2] + DP[i - 1];
        }
        return DP[n];
    }
};