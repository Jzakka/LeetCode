class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> res;

        int carry = 1;
        for (int i = len - 1; i >= 0; i--) {
            int digit = digits.at(i);
            res.push_back((digit + carry) % 10);
            carry = (digit + carry) >= 10 ? 1 : 0;
        }
        if(carry) res.push_back(carry);

        std::reverse(res.begin(), res.end());
        return res;
    }
};