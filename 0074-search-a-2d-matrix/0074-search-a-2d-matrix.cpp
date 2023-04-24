class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        int width = matrix.at(0).size();

        int start, mid, end;
        start = 0;
        end = height-1;
        mid = (start + end) / 2;
        while (start <= end) {
            if(matrix.at(mid).at(0) < target) {
                start = mid+1;
            } else if(matrix.at(mid).at(0) > target){
                end = mid-1;
            } else {
                return true;
            }
            mid = (start + end) / 2;
        }
        int row = mid;
        start=0;
        end = width - 1;
        mid = (start + end) / 2;
        while (start <= end) {
            if(matrix.at(row).at(mid) < target) {
                start = mid+1;
            } else if(matrix.at(row).at(mid) > target){
                end = mid-1;
            } else {
                return true;
            }
            mid = (start + end) / 2;
        }

        return false;
    }
};