class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> dupRemoved;
        vector<int> buck;
        std::for_each(nums.begin(), nums.end(), [&dupRemoved](const auto &num) {
            dupRemoved.insert(num);
        });
        for (auto &num: dupRemoved) {
            buck.push_back(num + 1'000'000'000);
        }
        vector<deque<int>> bucket(10);
        vector<vector<deque<int>>> buckets(10, bucket);

        for (int i = 1; i <= 10; i++) {
            for (auto &num: buck) {
                buckets[i - 1][num % (long) pow(10, i) / pow(10, i - 1)].push_back(num);
            }
            buck.clear();
            for (int j = 0; j < 10; j++) {
                while (!buckets[i - 1][j].empty()) {
                    buck.push_back(buckets[i - 1][j].front());
                    buckets[i - 1][j].pop_front();
                }
            }
        }

        int len = 1;
        int maxLen = INT32_MIN;
        for (auto it = buck.begin(); it + 1 != buck.end(); it++) {
            if (*(it + 1) - *it == 1) {
                len++;
            } else {
                maxLen = max(len, maxLen);
                len = 1;
            }
        }

        return max(maxLen,len);
    }
};