class Solution {
public:
    int minDistance(string word1, string word2) {
        int matrix[501][501];
        for (int i = 0; i < 501; i++) {
            matrix[i][0] = i;
            matrix[0][i] = i;
        }

        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.at(i - 1) == word2.at(j - 1)) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                } else {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                }
            }
        }

        return matrix[word1.length()][word2.length()];
    }
};