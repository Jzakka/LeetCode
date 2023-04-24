class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string res = "";

        std::sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            string num1 = to_string(a);
            string num2 = to_string(b);

            string cand1 = num1 + num2;
            string cand2 = num2 + num1;

            int strLen = cand1.length();
            for (int i = 0; i < strLen; i++) {
                if (cand1.at(i) < cand2.at(i)) {
                    return false;
                } else if (cand1.at(i) > cand2.at(i)) {
                    return true;
                }
            }
            return false;
        });
        for (auto &num: nums) {
            res += to_string(num);
        }
        if (res.length() >= 2 && res.front() == '0') {
            while (res.front() == '0' && res.length() > 1) {
                res.erase(res.begin());
            }
        }
        return res;
    }
};