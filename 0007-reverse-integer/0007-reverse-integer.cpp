class Solution {
public:
    int reverse(int x) {
        string intStr = to_string(x);
        std::reverse(intStr.begin(), intStr.end());
        long result = 0;

        if (*prev(intStr.end()) == '-') {
            auto &&it = intStr.begin();
            while (*it == '0') it++;

            int len = distance(it, prev(intStr.end() - 1));
            for (; it != prev(intStr.end()); it++, len--) {
                result -= (*it - '0') * pow(10, len);
                if (result <= INT32_MIN || result >= INT32_MAX) {
                    return 0;
                }
            }
        } else {
            auto &&it = intStr.begin();
            while (*it == '0') it++;

            int len = distance(it, intStr.end() - 1);
            for (; it != intStr.end(); it++, len--) {
                result += (*it - '0') * pow(10, len);
                if (result <= INT32_MIN || result >= INT32_MAX) {
                    return 0;
                }
            }
        }
        return result;
    }
};