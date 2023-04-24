class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp = {1};
        recursive(res, temp, 1, numRows);
        return res;
    }

    void recursive(vector<vector<int>> &res, vector<int>& temp, int level, int destination) {
        res.push_back(temp);
        if (level == destination) return;

        vector<int> nextArray;
        nextArray.push_back(1);
        for (int i = 0; i < temp.size() - 1; i++) {
            nextArray.push_back(temp[i] + temp[i + 1]);
        }
        nextArray.push_back(1);
        recursive(res, nextArray, level + 1, destination);
    }
};