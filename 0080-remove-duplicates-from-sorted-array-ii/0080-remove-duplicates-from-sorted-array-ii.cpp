class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int kind = 1;
        int prevNum = nums[0];
        int dupCnt = 0;
        int placeIdx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (prevNum == nums[i]) {
                dupCnt++;
            }else{
                prevNum = nums[i];
                kind++;
                dupCnt = 0;
            }
            if (dupCnt < 2) {
                nums[placeIdx] = nums[i];
                placeIdx++;
            }
        }
        return placeIdx;
    }
};
