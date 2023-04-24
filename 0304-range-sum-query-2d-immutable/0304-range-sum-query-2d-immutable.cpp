class NumMatrix {
private:
    vector<vector<int>> accSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        accSum = vector<vector<int>>(matrix.size(), vector<int>(matrix.at(0).size()));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                int up = 0;
                int left = 0;
                int cross = 0;

                if (i - 1 >= 0) {
                    up = accSum.at(i - 1).at(j);
                }
                if (j - 1 >= 0) {
                    left = accSum.at(i).at(j - 1);
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    cross = accSum.at(i - 1).at(j - 1);
                }

                accSum.at(i).at(j) = up + left - cross + matrix.at(i).at(j);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = 0;
        int left = 0;
        int cross = 0;

        if (col1 - 1 >= 0) {
            left = accSum.at(row2).at(col1 - 1);
        }
        if (row1 - 1 >= 0) {
            up = accSum.at(row1 - 1).at(col2);
        }
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            cross = accSum.at(row1 - 1).at(col1 - 1);
        }

        return accSum.at(row2).at(col2) - left - up + cross;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */