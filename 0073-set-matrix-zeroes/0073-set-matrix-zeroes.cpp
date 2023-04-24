class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(0).size(); j++) {
                if (matrix.at(i).at(j) == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        for (auto &e: zeros) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix.at(i).at(e.second) = 0;
            }
            for (int i = 0; i < matrix.at(0).size(); i++) {
                matrix.at(e.first).at(i) = 0;
            }
        }
    }
};