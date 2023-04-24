class NumArray {
private:
    vector<int> accSum;
public:
    NumArray(vector<int> &nums) {
        accSum = vector<int>(nums.size(), 0);
        int sum = 0;
        int idx = 0;
        for (int num: nums) {
            sum += num;
            accSum.at(idx++) = sum;
        }
    }

    int sumRange(int left, int right) {
        return accSum.at(right) - (left == 0 ? 0 : accSum.at(left - 1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */