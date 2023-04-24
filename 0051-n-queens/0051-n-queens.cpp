class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        string line = "";
        for (int i = 0; i < n; i++) {
            line += '.';
        }
        vector<string> board (n, line);
        for (unsigned i = 0; i < n; i++) {
            recursive(board, 0, i, n, n);
        }

        return res;
    }

    void recursive(vector<string> board, int row, int col, int remainQueens, const int n){
        if(row >= n) return;

        board[row].at(col) = 'Q';

        if(--remainQueens <= 0) {
            res.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if(available(board, row+1 , j, n))
                recursive(board, row+1, j, remainQueens, n);
        }
    }

    bool available(const vector<string> &board, int row, int col, const int n){
        for (auto &r: board) {
            if(r.at(col) == 'Q') return false;
        }
        int i,j;
        i = row;j=col;
        while (i < n && j <n && 0 <= i && 0 <= j){
            if(board[i--].at(j--) =='Q') return false;
        }
        i = row;j=col;
        while (i < n && j <n && 0 <= i && 0 <= j){
            if(board[i--].at(j++) =='Q') return false;
        }
        i = row;j=col;
        while (i < n && j <n && 0 <= i && 0 <= j){
            if(board[i++].at(j++) =='Q') return false;
        }
        i = row;j=col;
        while (i < n && j <n && 0 <= i && 0 <= j){
            if(board[i++].at(j--) =='Q') return false;
        }

        return board[row].find('Q') == -1;
    }
};