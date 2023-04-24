
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int v = 0;
        int w = 0;

        do {
            v = nums[v];
            w = nums[nums[w]];
        } while (nums[v] != nums[w]);

        w = 0;
        while (nums[v] != nums[w]) {
            v = nums[v];
            w = nums[w];
        }

        return nums[v];
    }
};