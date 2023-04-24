class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> array;
        for (int i = 1; i <= n; i++) {
            array.push_back(i);
        }

        int cnt = k - 1;
        while (cnt--) {
            std::next_permutation(array.begin(), array.end());
        }

        string res = "";
        for (auto &c: array) {
            res += c + '0';
        }

        return res;
    }
};