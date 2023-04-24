
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j;
        i = 0;
        j = numbers.size() - 1;
        int sum;
        while ((sum = numbers[i] + numbers[j]) != target) {
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {i+1, j+1};
    }
};