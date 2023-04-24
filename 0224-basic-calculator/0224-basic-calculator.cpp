
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        char prevOp = '+';
        int opResult;
        for (auto it = s.begin(); it != s.end(); it++) {
            char letter = *it;
            if (letter >= '0' && letter <= '9') {
                opResult = parseNumberString(s, it);
                calculate(result, prevOp, opResult);
            } else if (letter == '(') {
                opResult = exe(s, ++it);
                calculate(result, prevOp, opResult);
            } else if (letter == '-') {
                prevOp = '-';
            } else if (letter == '+') {
                prevOp = '+';
            }
        }
        return result;
    }

    void calculate(int &result, char prevOp, int opResult) {
        if (prevOp == '-') {
            result -= opResult;
        } else {
            result += opResult;
        }
    }

    int exe(string &s, string::iterator &it) {
        int result = 0;
        char prevOp = '+';
        int opResult;
        for (; it != s.end(); it++) {
            char letter = *it;
            if (letter >= '0' && letter <= '9') {
                opResult = parseNumberString(s, it);
                calculate(result, prevOp, opResult);
            } else if (letter == '(') {
                opResult = exe(s, ++it);
                calculate(result, prevOp, opResult);
            } else if (letter == '-') {
                prevOp = '-';
            } else if (letter == '+') {
                prevOp = '+';
            } else if (letter == ')') {
                return result;
            }
        }
        return result;
    }

    int parseNumberString(string &s, string::iterator &it) {
        int result = 0;

        int exp = 0;
        for (; next(it) != s.end() && (*next(it)) >= '0' && (*next(it)) <= '9';
               it++, exp++, result *= 10) {
            int digit = *it - '0';
            result += digit;
        }
        result += *it - '0';
        return result;
    }
};