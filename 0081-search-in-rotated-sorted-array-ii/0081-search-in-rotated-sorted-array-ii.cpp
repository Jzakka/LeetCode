class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int sz = nums.size();
        int l = 0;
        int r = sz - 1;
        int mid = (l + r) / 2;

        while (l < r) {
            int leftNum = nums[l];
            int midNum = nums[mid];
            int rightNum = nums[r];

            if(midNum == target || leftNum == target || rightNum == target){
                return true;
            }
            // 양단이 같음 => 판단 불가 => 양끝을 좁힘
            else if(leftNum == rightNum){
                l++;
                r--;
            } else if (leftNum <= midNum) {
                if (leftNum <= target && target < midNum) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }else{
                if (midNum <= target && target < rightNum) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            mid = (l + r) / 2;
        }
        return nums[l] == target;
    }
};
