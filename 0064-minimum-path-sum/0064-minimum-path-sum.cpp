class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        int matrix[height][width];
        matrix[0][0] = grid[0][0];
        for (int i = 1; i < height; i++) {
            matrix[i][0] = matrix[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < width; i++) {
            matrix[0][i] = matrix[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                matrix[i][j] = grid[i][j] + min(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }

        return matrix[height - 1][width - 1];
    }
};