class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> pack;
        for (int i = 1; i <= n; i++) {
            recursive(pack, i,n, k-1);
        }
        return res;
    }

    void recursive(vector<int>& pack, int picked, int n, int remains) {
        pack.push_back(picked);

        if (remains == 0) {
            res.push_back(pack);
            pack.pop_back();
            return;
        }

        for (int i = picked + 1; i <= n; i++) {
            recursive(pack, i, n, remains - 1);
        }
        pack.pop_back();
    }
};