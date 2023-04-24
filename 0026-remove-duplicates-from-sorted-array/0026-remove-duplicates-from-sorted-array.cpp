class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();

        if(k<2) return k;

        int fix = 1;
        for (int i = 1; i < k; i++) {
            if(nums[i]!=nums[i-1]) nums[fix++] = nums[i];
        }
        return fix;
    }
};