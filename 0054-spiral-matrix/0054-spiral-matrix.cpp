class Solution {
private:
    vector<int> result;
    vector<pair<int,int>> direction = {{0,1}, {1,0}, {0, -1}, {-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<vector<bool>> visited;
        int height = matrix.size();
        int width = matrix.at(0).size();
        for (int i = 0; i < height; i++) {
            visited.push_back(vector<bool>(width, false));
        }
        int area = height * width;
        int dirIdx = 0;

        visit(matrix, 0, 0, 0, dirIdx, height, width, area, visited);

        return result;
    }

    void visit(const vector<vector<int>> &matrix, int cnt, int x, int y, int dirIdx,
               int height, int width, int area, vector<vector<bool>> &visited) {
        result.push_back(matrix.at(x).at(y));
        visited.at(x).at(y) = true;
        if (++cnt == area) return;

        int nextX = x + direction.at(dirIdx).first;
        int nextY = y + direction.at(dirIdx).second;

        if(nextX < 0 || nextX >= height || nextY < 0 || nextY >= width || visited.at(nextX).at(nextY)){
            dirIdx++;
            if(dirIdx >= 4) dirIdx = 0;
            nextX = x + direction.at(dirIdx).first;
            nextY = y + direction.at(dirIdx).second;
        }

        visit(matrix, cnt, nextX, nextY, dirIdx, height, width, area, visited);
    }
};