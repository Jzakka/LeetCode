
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return radixSort(nums).at(nums.size() - k);
    }

    vector<int> radixSort(vector<int> nums){
        std::for_each(nums.begin(), nums.end(),[](int& num){
           num += 10000;
        });
        for (int i = 0; i < 5; i++) {
            vector<list<int>> buck(10);
            for (auto &num: nums) {
                int ithDigit = getithDigit(num, i);
                buck.at(ithDigit).push_back(num);
            }
            int idx = 0;
            for (int j = 0; j < 10; j++) {
                for (auto &num: buck.at(j)) {
                    nums.at(idx++) = num;
                }
            }
        }
        std::for_each(nums.begin(), nums.end(),[](int& num){
            num -= 10000;
        });
        return nums;
    }

    int getithDigit(int num, int i){
        return num % (int)pow(10, i + 1) / pow(10, i);
    }
};