
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int exp = 0;
        for (auto it = columnTitle.end() - 1; it >= columnTitle.begin(); it--, exp++) {
            res += ((*it) - 'A' + 1) * pow(26, exp);
        }
        return res;
    }
};