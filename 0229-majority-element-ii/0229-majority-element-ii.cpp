
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        if (nums.empty()) {
            res =  {};
        } else if (nums.size() == 1){
            res = nums;
        } else if(nums.size() == 2) {
            res.push_back(nums.front());
            if (nums.front() != nums.back()) {
                res.push_back(nums.back());
            }
        } else {
            int major1, major2, cnt1, cnt2;
            major1 = major2 = INT32_MIN;
            cnt1 = 0;
            cnt2 = 0;

            loop(major1, major2, cnt1, cnt2, nums);


            if (std::count(nums.begin(), nums.end(), major1) > nums.size() / 3) {
                res.push_back(major1);
            }
            if (std::count(nums.begin(), nums.end(), major2) > nums.size() / 3) {
                res.push_back(major2);
            }
        }
        return res;
    }

    void loop(int& major1,int& major2,int& cnt1,int& cnt2,vector<int>&nums){
        for (auto &num: nums) {
            if (num == major1) {
                cnt1++;
            } else if (num == major2) {
                cnt2++;
            } else if (!cnt1) {
                major1 = num;
                cnt1 = 1;
            } else if (!cnt2) {
                major2 = num;
                cnt2 = 1;
            }else {
                cnt1--;
                cnt2--;
            }
        }
    }
};