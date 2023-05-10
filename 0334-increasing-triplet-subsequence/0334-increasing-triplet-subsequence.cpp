class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        long first, second;
        first = LONG_MAX;
        second = LONG_MAX;

        long goal = LONG_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums.at(i);

            if (num > goal) {
                return true;
            }
            if (num < second) {
                if (num < first) {
                    first = num;
                    second = LONG_MAX;
                } else if (num > first) {
                    second = num;
                    goal = min(goal, second);
                }
            }
        }

        return false;
    }
};