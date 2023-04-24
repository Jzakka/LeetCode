class Solution {
public:
    std::string convert(std::string s, int numRows) {
        int totalJump = (numRows - 1) * 2;
        int strLen = s.length();
        if(strLen == 1 || numRows == 1) return s;

        std::string converted = "";

        for (int i = 0; i < numRows; i++) {
            int first = totalJump - i * 2;
            int second = i * 2;
            bool isFirst = false;
            for (int j = i;
                 j < strLen; j += (first == 0 || second == 0) ? std::max(first, second) : isFirst ? first : second) {
                converted += s.at(j);
                isFirst = !isFirst;
            }
        }

        return converted;
    }
};