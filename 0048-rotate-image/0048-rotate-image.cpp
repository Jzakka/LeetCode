class Solution {
private:
    void move(vector<vector<int>> &matrix, int length, pair<int,int> criterion){
        auto leftUp = criterion;
        pair<int,int> leftDown = {length - leftUp.second - 1, leftUp.first};
        pair<int,int> rightDown = {length - leftDown.second - 1, leftDown.first};
        pair<int,int> rightUp = {length - rightDown.second - 1, rightDown.first};

        int temp = matrix[leftUp.first][leftUp.second];

        matrix[leftUp.first][leftUp.second] = matrix[leftDown.first][leftDown.second];
        matrix[leftDown.first][leftDown.second] = matrix[rightDown.first][rightDown.second];
        matrix[rightDown.first][rightDown.second] = matrix[rightUp.first][rightUp.second];
        matrix[rightUp.first][rightUp.second] = temp;
    }
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        int rightPadding = 1;
        for (int i = 0; i <= (n + 1)/2 -1; i++, rightPadding++) {
            for (int j = i; j < n - rightPadding; j++) {
                move(matrix, n, {i, j});
            }
        }
    }
};