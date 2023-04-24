class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber) {
            int digit = columnNumber % 26;
            if (digit != 0) {
                res = (char) ('A' + digit - 1) + res;
                columnNumber /= 26;
            } else {
                res = 'Z' + res;
                columnNumber /= 26;
                columnNumber--;
            }
        }
        return res;
    }
};