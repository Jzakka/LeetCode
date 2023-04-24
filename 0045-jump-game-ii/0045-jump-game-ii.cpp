class Solution {
public:
    int jump(vector<int> &nums) {
        int dest = nums.size() - 1;
        int cnt,start,end,maximum;
        cnt = start = end = 0;

        while (cnt < dest) {
            cnt++;

            maximum = end + 1;
            for (int i = start; i <= end; i++) {
                if(i + nums[i] >= dest) return cnt;
                maximum = max(maximum, i + nums[i]);
            }
            start = end + 1;
            end = maximum;
        }

        return cnt;
    }
};
