class Solution {
private:
    vector<pair<int, int>> dir = {{0,  1},
                                  {1,  0},
                                  {0,  -1},
                                  {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<int>(n, -1));
        }

        int x = 0;
        int y = 0;
        int dirIdx = 0;
        auto direction = dir.at(dirIdx);
        for (int i = 1; i <= n * n; i++) {
            res.at(x).at(y) = i;
            int nextX = x + direction.first;
            int nextY = y + direction.second;

            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || res.at(nextX).at(nextY) != -1){
                direction = dir.at((++dirIdx) % 4);
                nextX = x + direction.first;
                nextY = y + direction.second;
            }
            x = nextX;
            y = nextY;
        }

        return res;
    }
};