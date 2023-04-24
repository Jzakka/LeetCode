
class Solution {
private:
    map<pair<int, int>, queue<int>> possible;
public:
    void solveSudoku(vector<vector<char>> &board) {
        vector<pair<int, int>> empty;
        unsigned i, j;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') empty.push_back({i, j});
            }
        }

        for (auto it = empty.begin(); it != empty.end();) {
//            sleep(1);
//            cout << (*it).first << " " << (*it).second << "\n";

            // 숫자큐가 이미 있으면 거기서 조작, 없으면 생성
            if (possible.find(*it) == possible.end()) {
                makeQueue(board, *it);
            }
            // 숫자큐가 비어있으면 이터레이터 감소하고 컨티뉴
            if (possible[*it].empty()) {
                possible.erase(*it);
                board[(*it).first][(*it).second] = '.';
                it--;
                continue;
            }
            // 숫자 큐의 맨앞을 할당&디큐
            board[(*it).first][(*it).second] = possible[*it].front()+'0';
            possible[*it].pop();
            it++;
//            printBoard(board);
        }
    }

    void printBoard(vector<vector<char>>& board){
        for (unsigned i = 0; i < 9; i++) {
            for (unsigned j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "================\n";
    }

    void makeQueue(vector<vector<char>> &board, pair<int, int> location) {
        unsigned i,j;
        int x = location.second;
        int y = location.first;
        vector<bool> available(10, true);

        for (i = 0; i < 9; i++) {
            if(board[y][i] != '.') available[board[y][i] - '0'] = false;
            if(board[i][x] != '.') available[board[i][x] - '0'] = false;
        }

        int block_x = x/3*3;
        int block_y = y/3*3;
        for (i = block_y; i < block_y + 3; i++) {
            for (j = block_x; j < block_x + 3; j++) {
                if(board[i][j] != '.') available[board[i][j] - '0'] = false;
            }
        }

        for (i = 1; i <= 9; i++) {
            if(available[i]) possible[location].push(i);
        }
    }
};