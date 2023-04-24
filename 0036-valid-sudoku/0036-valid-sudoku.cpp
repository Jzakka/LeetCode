class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for(unsigned i = 0;i<9;i++){
            vector<int> repeat(10,0);
            for(unsigned j = 0;j<9;j++){
                if(board[i][j] != '.' && ++repeat[board[i][j]-'0'] >= 2){
                    return false;
                }
            }
        }

        // col
        for(unsigned i = 0;i<9;i++){
            vector<int> repeat(10,0);
            for(unsigned j = 0;j<9;j++){
                if(board[j][i] != '.' && ++repeat[board[j][i]-'0'] >= 2){
                    return false;
                }
            }
        }

        // 3x3
        for(unsigned i = 0;i<9;i+=3){
            for(unsigned j = 0;j<9;j+=3){
                vector<int> repeat(10,0);
                for(unsigned _i = i;_i<i+3;_i++){
                    for(unsigned _j = j;_j<j+3;_j++){
                        if(board[_i][_j] != '.' && ++repeat[board[_i][_j]-'0'] >= 2){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};