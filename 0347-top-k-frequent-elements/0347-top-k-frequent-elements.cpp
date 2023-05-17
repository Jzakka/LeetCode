class Solution {
public:
    struct NumCount {
        int number;
        int count;

        NumCount() {}

        NumCount(int number, int count) : number(number), count(count) {}

        int numberOf(int place) {
            return count % (int) pow(10, place + 1) / (int) pow(10, place);
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> numberCnt;
        for (const auto &num: nums) {
            numberCnt[num]++;
        }
        return uniqueSorted(numberCnt, k);
    }

    // 빈도 1 ~ 100000

    vector<int> uniqueSorted(unordered_map<int, int> &numberCnt, int k) {
        vector<NumCount *> numCounts;
        for (const auto &entry: numberCnt) {
            numCounts.emplace_back(new NumCount(entry.first, entry.second));
        }
        vector<vector<NumCount *>> bucket = {numCounts};

        for (int i = 0; i <= 5; i++) {
            bucket = bucketSort(bucket, i);
        }

        unordered_set<int> resSet;
        for (int place = 9; place >= 0 && resSet.size() < k; place--) {
            int lengthOfNthPlaceBucket = bucket.at(place).size();
            for (int i = lengthOfNthPlaceBucket - 1; i >= 0 && resSet.size() < k; i--) {
                resSet.insert(bucket.at(place).at(i)->number);
            }
        }
        return vector<int>(resSet.begin(), resSet.end());
    }

    vector<vector<NumCount *>> bucketSort(vector<vector<NumCount *>> &bucket, int place) {
        vector<vector<NumCount *>> newBuck(10);

        for (const auto &elementList: bucket) {
            for (const auto &element: elementList) {
                int digit = element->numberOf(place);
                newBuck.at(digit).push_back(element);
            }
        }

        return newBuck;
    }
};