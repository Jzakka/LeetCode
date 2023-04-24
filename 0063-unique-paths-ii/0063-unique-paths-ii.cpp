class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid.at(0).size();
        int matrix[height][width];
        matrix[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < height; i++) {
            matrix[i][0] = obstacleGrid[i][0] != 1 ? matrix[i - 1][0] : 0;
        }
        for (int i = 1; i < width; i++) {
            matrix[0][i] = obstacleGrid[0][i] != 1 ? matrix[0][i - 1] : 0;
        }

        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                if (obstacleGrid[i][j] != 1) {
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        return matrix[height - 1][width - 1];
    }
};