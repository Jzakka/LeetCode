class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid.front().size();

        int cnt = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.at(i).at(j) == '1' && visited.at(i).at(j) == 0) {
                    dfs(grid, visited, m, n, i, j, ++cnt);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int m, int n,
             int i, int j, int &cnt) {
        if (i >= m || j >= n || i < 0 || j < 0
            || grid.at(i).at(j) == '0' || visited.at(i).at(j) > 0) {
            return;
        }
        visited.at(i).at(j) = cnt;
        dfs(grid, visited, m, n, i + 1, j, cnt);
        dfs(grid, visited, m, n, i, j + 1, cnt);
        dfs(grid, visited, m, n, i - 1, j, cnt);
        dfs(grid, visited, m, n, i, j - 1, cnt);
    }
};