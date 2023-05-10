class Solution {
public:
    struct Cell {
        int x, y, number;

        Cell(int x, int y, int number) : x(x), y(y), number(number) {}

        const bool operator<(Cell cell) const {
            return this->number < cell.number;
        }
    };

    vector<vector<bool>> visited;
    vector<vector<int>> DP;
    int m, n;
    vector<vector<int>> matrix;

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        vector<Cell> cells;
        m = matrix.size();
        n = matrix.front().size();
        visited = vector<vector<bool>>(m, vector<bool>(n));
        DP = vector<vector<int>>(m, vector<int>(n, -1));
        this->matrix = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back(Cell(i, j, matrix.at(i).at(j)));
            }
        }

        std::sort(cells.begin(), cells.end());

        int maxLen = 0;
        for (const auto &cell: cells){
            int len = maxLenPath(cell.x, cell.y, 0) + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }

    vector<pair<int, int>> getNext(int x, int y) {
        vector<pair<int, int>> res;
        int curNum = matrix.at(x).at(y);

        if (x - 1 >= 0 && !visited.at(x-1).at(y) && matrix.at(x-1).at(y) > curNum) {
            res.push_back({x - 1, y});
        }
        if (x + 1 < m && !visited.at(x+1).at(y) && matrix.at(x+1).at(y) > curNum) {
            res.push_back({x + 1, y});
        }
        if (y - 1 >= 0 && !visited.at(x).at(y-1) && matrix.at(x).at(y-1) > curNum) {
            res.push_back({x, y - 1});
        }
        if (y + 1 < n  && !visited.at(x).at(y+1) && matrix.at(x).at(y+1) > curNum) {
            res.push_back({x, y + 1});
        }

        return res;
    }

    int maxLenPath(int x, int y, int dist) {
        if (visited.at(x).at(y)) {
            return 0;
        }
        if (DP.at(x).at(y) != -1) {
            return dist + DP.at(x).at(y);
        }

        visited.at(x).at(y) = true;

        vector<pair<int, int>> next = getNext(x, y);
        int maxLen = dist;
        for (const auto &nextPos: next) {
            int len = maxLenPath(nextPos.first, nextPos.second, dist + 1);
            maxLen = max(maxLen, len);
        }

        DP.at(x).at(y) = maxLen - dist;

        visited.at(x).at(y) = false;

        return maxLen;
    }
};