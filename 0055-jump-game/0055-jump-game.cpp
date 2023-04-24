class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();

        int start, end, maxJump;

        start = end = maxJump = 0;

        while (start <= sz - 1) {
            maxJump = end;

            for(int i = start; i<=end;i++){
                if(i + nums.at(i) >= sz - 1) return true;
                maxJump = max(maxJump, i + nums.at(i));
            }
            start = end+1;
            if(maxJump == end) return false;
            end = maxJump;
        }
        return true;
    }
};
