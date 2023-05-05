class Solution {
public:
    vector<int> monotoneStack(unordered_map<int, vector<int>> &DP, vector<int> &nums, int size) {
        if (size == nums.size()) {
            DP[size] = nums;
            return nums;
        }

        auto preRemoved = monotoneStack(DP, nums, size + 1);
        vector<int> res;
        int i = 0;
        for (; i < preRemoved.size() - 1; i++) {
            int num1 = preRemoved.at(i);
            int num2 = preRemoved.at(i + 1);

            if (num1 < num2) {
                break;
            }
        }

        for (int j = 0; j < preRemoved.size(); j++) {
            if (j != i) {
                res.push_back(preRemoved.at(j));
            }
        }

        DP[size] = res;
        return res;
    }

    vector<int> merge(vector<int> &left, vector<int> &right) {
        vector<int> merged;
        int leftCursor = 0;
        int rightCursor = 0;

        while (leftCursor < left.size() && rightCursor < right.size()) {
            if (left.at(leftCursor) > right.at(rightCursor)) {
                merged.push_back(left.at(leftCursor++));
            } else if (left.at(leftCursor) < right.at(rightCursor)) {
                merged.push_back(right.at(rightCursor++));
            } else {
                vector<int> bigger = compareVector(left, right, leftCursor, rightCursor);
                if (bigger == left) {
                    merged.push_back(left.at(leftCursor++));
                } else {
                    merged.push_back(right.at(rightCursor++));
                }
            }
        }

        while (leftCursor < left.size()) {
            merged.push_back(left.at(leftCursor++));
        }

        while (rightCursor < right.size()) {
            merged.push_back(right.at(rightCursor++));
        }

        return merged;
    }

    vector<int> compareVector(vector<int> &left, vector<int> &right, int leftStart, int rightStart) {
        int i = 0;
        int leftPos = i + leftStart;
        int rightPos = i + rightStart;
        for (; leftPos < left.size() && rightPos < right.size(); leftPos++, rightPos++) {
            if (left.at(leftPos) > right.at(rightPos)) {
                return left;
            } else if (left.at(leftPos) < right.at(rightPos)) {
                return right;
            }
        }

        if (leftPos == left.size()) {
            return right;
        }
        return left;
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        unordered_map<int, vector<int>> left;
        unordered_map<int, vector<int>> right;
        monotoneStack(left, nums1, 0);
        monotoneStack(right, nums2, 0);

        vector<int> res(k, -1);

        for (int i = 0; i <= min(k, (int) nums1.size()); i++) {
            int leftSz = i;
            int rightSz = k - i;
            if (rightSz <= nums2.size()) {
                vector<int> merged = merge(left[leftSz], right[rightSz]);
                res = compareVector(res, merged, 0, 0);
            }
        }

        return res;
    }
};