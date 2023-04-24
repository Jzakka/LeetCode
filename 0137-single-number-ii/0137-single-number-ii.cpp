class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map(30001);

        for(auto & num:nums){
            map[num]++;
        }

        for (auto &cnt: map) {
            if (cnt.second == 1) {
                return cnt.first;
            }
        }

        return -1;
    }
};