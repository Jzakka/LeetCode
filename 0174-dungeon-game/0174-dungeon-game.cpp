class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon.front().size();
        vector<vector<int>> minHp(m, vector<int>(n));

        minHp.at(m - 1).at(n - 1) = max(-dungeon.at(m - 1).at(n - 1), 0);

        for (int i = m - 2; i >= 0; i--) {
            int prevHp = minHp.at(i + 1).at(n - 1);
            int delta = dungeon.at(i).at(n - 1);
            minHp.at(i).at(n - 1) = max(prevHp - delta, 0);
        }
        for (int j = n - 2; j >= 0; j--) {
            int prevHp = minHp.at(m - 1).at(j + 1);
            int delta = dungeon.at(m - 1).at(j);
            minHp.at(m - 1).at(j) = max(prevHp - delta, 0);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                minHp.at(i).at(j) = max(min(minHp.at(i + 1).at(j), minHp.at(i).at(j + 1)) - dungeon.at(i).at(j), 0);
            }
        }
        return minHp.at(0).at(0)+1;
    }
};