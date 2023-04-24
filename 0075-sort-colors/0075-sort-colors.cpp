class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        for (auto &e: nums) {
            switch (e) {
                case 0:
                    red++;
                    break;
                case 1:
                    white++;
                    break;
                default:
                    blue++;
            }
        }
        int idx = 0;
        for (int i = 0; i < red; i++, idx++) {
            nums.at(idx) = 0;
        }
        for (int i = 0; i < white; i++, idx++) {
            nums.at(idx) = 1;
        }
        for (int i = idx; i < nums.size(); i++) {
            nums.at(i) = 2;
        }
    }
};