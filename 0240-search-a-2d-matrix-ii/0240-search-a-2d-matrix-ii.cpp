
class Solution {
private:
    int n;
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        n = matrix.front().size();

        for (auto &line: matrix) {
            if (binarySearch(line, target, 0, n)) {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(const vector<int> &arr, int target ,int s, int e) {
        int m;
        while (s < e) {
            m = (s + e)/2;
            if (target == arr.at(m)) {
                return true;
            } else if (target < arr.at(m)) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return false;
    }
};