class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                deadOrAlive(board,i,j);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }

    void deadOrAlive(vector<vector<int>> &board, int i, int j){
        int _12 = getAround(board, i-1, j);
        int _1 = getAround(board, i-1, j+1);
        int _3 = getAround(board, i, j+1);
        int _5 = getAround(board, i+1, j+1);
        int _6 = getAround(board, i+1, j);
        int _7 = getAround(board, i+1, j-1);
        int _9 = getAround(board, i, j-1);
        int _10 = getAround(board, i-1, j-1);

        int countOfLive = _1 + _3 + _5 + _6 + _7 + _9 + _10 + _12;
        if (board[i][j]&1 && countOfLive != 2 && countOfLive != 3) {
            board[i][j] = 3;
        } else if (!(board[i][j] & 1) && countOfLive == 3) {
            board[i][j] = 2;
        }
    }

    int getAround(vector<vector<int>> &board, int i, int j){
        if (i >= board.size() || i < 0 || j >= board.at(0).size() || j < 0) {
            return 0;
        }
        return board[i][j] & 1;
    }
};