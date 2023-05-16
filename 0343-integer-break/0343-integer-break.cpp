class Solution {
public:
    int integerBreak(int n) {
        int maxMul = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> broken = breakTo(n, i);
            maxMul = max(maxMul, mul(broken));
        }
        return maxMul;
    }

    vector<int> breakTo(int n, int k) {
        vector<int> broken(k, n / k);
        int remain = n - n / k * k;
        for (int i = 0; i < remain; i++) {
            broken.at(i)++;
        }
        return broken;
    }

    int mul(vector<int> &broken){
        int mul = 1;
        for (const auto &item: broken){
            mul *= item;
        }
        return mul;
    }
};