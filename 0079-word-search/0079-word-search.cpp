class Solution {
private:
    bool visited[37][37];
    string word;
    int height;
    int width;
public:
    bool exist(vector<vector<char>> &board, string word) {
        this->word = word;
        height = board.size();
        width = board[0].size();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0] && recursive(board, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool recursive(vector<vector<char>> &board, int i, int j, int idx) {
        visited[i][j] = true;
        if (idx == word.length() - 1) {
            return true;
        }
        int nextX, nextY;
        //up
        nextX = i - 1;
        nextY = j;
        if (nextX >= 0 && nextX < height
            && !visited[nextX][nextY]
            && (board[nextX][nextY] == word[idx + 1])
            && recursive(board, nextX, nextY, idx + 1))
            return true;
        //down
        nextX = i + 1;
        nextY = j;
        if (nextX >= 0 && nextX < height
            && !visited[nextX][nextY]
            && (board[nextX][nextY] == word[idx + 1])
            && recursive(board, nextX, nextY, idx + 1))
            return true;
        //left
        nextX = i;
        nextY = j - 1;
        if (nextY >= 0 && nextY < width
            && !visited[nextX][nextY]
            && (board[nextX][nextY] == word[idx + 1])
            && recursive(board, nextX, nextY, idx + 1))
            return true;
        //right
        nextX = i;
        nextY = j + 1;
        if (nextY >= 0 && nextY < width
            && !visited[nextX][nextY]
            && (board[nextX][nextY] == word[idx + 1])
            && recursive(board, nextX, nextY, idx + 1))
            return true;

        visited[i][j] = false;
        return false;
    }
};