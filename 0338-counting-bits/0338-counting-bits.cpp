class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);

        for (int i = 0; i <= n / 2; i++) {
            result.at(i * 2) = result.at(i);
            if (i * 2 + 1 <= n) {
                result.at(i * 2 + 1) = result.at(i) + 1;
            }
        }

        return result;
    }
};