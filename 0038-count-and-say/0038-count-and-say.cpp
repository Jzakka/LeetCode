class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string result = "";
        int cnt = 1;
        for (auto it = prev.begin(); it != prev.end(); it++) {
            if (it + 1 != prev.end() && (*it) == *(it + 1)) {
                cnt++;
            } else {
                result += (char) (cnt + '0');
                result += (*it);
                cnt = 1;
            }
        }
        return result;
    }
};