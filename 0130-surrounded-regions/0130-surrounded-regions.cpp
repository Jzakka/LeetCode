class Solution {
private:
    int row, col;
    bool except[201][201];
    set<vector<int>> visitedEdge;
    map<pair<int, int>, bool> DP;
public:
    void solve(vector<vector<char>> &board) {
        row = board.size();
        col = board.at(0).size();

        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                infect(board, 0, i, 1);
            }
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                infect(board, i, 0, 1);
            }
        }

        for (int i = col - 1; i >= 0; i--) {
            if (board[row - 1][i] == 'O') {
                infect(board, row - 1, i, -1);
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col - 1] == 'O') {
                infect(board, i, col - 1, -1);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && !except[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void infect(vector<vector<char>> &board, int x, int y, int dir) {
        except[x][y] = true;

        if (!areaOut(x + 1, y)
            && board[x + 1][y] == 'O'
            && visitedEdge.find({x, y, x + 1, y}) == visitedEdge.end()) {
            visitedEdge.insert({x, y, x + 1, y});
            visitedEdge.insert({x + 1, y, x, y});
            infect(board, x + 1, y, dir);
        }
        if (!areaOut(x - 1, y)
            && board[x - 1][y] == 'O'
            && visitedEdge.find({x, y, x - 1, y}) == visitedEdge.end()) {
            visitedEdge.insert({x, y, x - 1, y});
            visitedEdge.insert({x - 1, y, x, y});
            infect(board, x - 1, y, dir);
        }
        if (!areaOut(x, y + 1)
            && board[x][y + 1] == 'O'
            && visitedEdge.find({x, y, x, y + 1}) == visitedEdge.end()) {
            visitedEdge.insert({x, y, x, y + 1});
            visitedEdge.insert({x, y + 1, x, y});
            infect(board, x, y + 1, dir);
        }
        if (!areaOut(x, y - 1)
            && board[x][y - 1] == 'O'
            && visitedEdge.find({x, y, x, y - 1}) == visitedEdge.end()) {
            visitedEdge.insert({x, y, x, y - 1});
            visitedEdge.insert({x, y - 1, x, y});
            infect(board, x, y - 1, dir);
        }
    }

    bool areaOut(int x, int y) {
        return !(0 <= x && x < row && 0 <= y && y < col);
    }
};