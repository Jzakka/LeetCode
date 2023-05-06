class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        vector<long> prefixSum;
        prefixSum.push_back(0);
        long sum = 0;
        for (const auto &num: nums) {
            sum += num;
            prefixSum.push_back(sum);
        }

        return recursive(prefixSum, 0, prefixSum.size(), lower, upper);
    }

    int recursive(vector<long> &prefixSum, int start, int end, int lower, int upper) {
        int mid = (start + end) / 2;
        if (mid == start) {
            return 0;
        }
        int count = recursive(prefixSum, start, mid, lower, upper) + recursive(prefixSum, mid, end, lower, upper);
        int i, j;
        i = j = mid;
        for (int k = start; k < mid; k++) {
            long left = prefixSum.at(k);

            while (i < end && prefixSum.at(i) - left < lower) {
                i++;
            }
            while (j < end && prefixSum.at(j) - left <= upper) {
                j++;
            }
            count += j - i;
        }
        sort(prefixSum.begin() + start, prefixSum.begin() + end);
        return count;
    }
};