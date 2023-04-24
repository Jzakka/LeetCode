class Solution {
private:
    void
    findSmallestIdx(const vector<vector<short>> &maxRights, stack<short> &smallest, vector<vector<short>> &vertical,
                    short j, short i, short dummyVal) {
        while (!smallest.empty() && maxRights[i][j] <= maxRights[smallest.top()][j]) {
            smallest.pop();
        }
        vertical[i][j] = (smallest.empty() ? dummyVal : smallest.top());
        smallest.push(i);
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        short height = matrix.size();
        short width = matrix[0].size();
        vector<vector<short>> maxRights(height, vector<short>(width + 1, 0));

        //calc maxRight
        for (int i = height - 1; i >= 0; i--) {
            for (int j = width - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    maxRights[i][j] = maxRights[i][j + 1] + 1;
                } else {
                    maxRights[i][j] = 0;
                }
            }
        }
        //calc maxUp
        //calc maxDown
        vector<vector<short>> up(height, vector<short>(width));
        vector<vector<short>> down(height, vector<short>(width));
        stack<short> smallest;
        for (int j = 0; j < width; j++) {
            for (int i = 0; i < height; i++) {
                findSmallestIdx(maxRights, smallest, up, j, i, -1);
            }
            smallest = stack<short>();
            for (int i = height - 1; i >= 0; i--) {
                findSmallestIdx(maxRights, smallest, down, j, i, height);
            }
            smallest = stack<short>();
        }

        int maxArea = 0;
        //calc maxArea
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                maxArea = max(maxArea, maxRights[i][j] * (down[i][j] - up[i][j] - 1));
            }
        }
        return maxArea;
    }
};