
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        vector<vector<int>> DP(m, vector<int>(n, 0));
        int maxSqr = 0;

        for (int i = 0; i < m; i++) {
            DP.at(i).at(0) = matrix.at(i).at(0) - '0';
            if(DP.at(i).at(0)){
                maxSqr = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            DP.at(0).at(i) = matrix.at(0).at(i) - '0';
            if(DP.at(0).at(i)){
                maxSqr = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                DP.at(i).at(j) = matrix.at(i).at(j) - '0';
                if (matrix.at(i).at(j) == '1') {
                    int left = matrix.at(i).at(j - 1);
                    int up = matrix.at(i-1).at(j);
                    int leftUp = matrix.at(i - 1).at(j - 1);

                    if (left == '1' && up == '1' && leftUp == '1') {
                        DP.at(i).at(j) = min(DP.at(i - 1).at(j - 1), min(DP.at(i).at(j - 1),DP.at(i - 1).at(j))) + 1;
                    }
                }
                int sqLen = DP.at(i).at(j);
                maxSqr = max(maxSqr, sqLen * sqLen);
            }
        }
        return maxSqr;
    }
};