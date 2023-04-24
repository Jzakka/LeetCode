class Solution {
private:
    int DP[201][201];
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        //init
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                DP[i][j] = INT32_MIN;
            }
        }
        return DFS(triangle, 0, 0);
    }

    int DFS(const vector<vector<int>> &triangle, int row, int col){
        if(DP[row][col] != INT32_MIN){
            return DP[row][col];
        }
        if (row >= triangle.size()) {
            return 0;
        }
        int left = DFS(triangle, row + 1, col);
        int right = DFS(triangle, row + 1, col + 1);
        int res = min(left, right) + triangle[row][col];
        DP[row][col] = res;
        return res;
    }
};
