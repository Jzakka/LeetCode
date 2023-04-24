class Solution {
public:
    bool isDigit(string::iterator iter) {
        return '0' <= *iter && *iter <= '9';
    }

    int myAtoi(string s) {
        long result = 0;
        auto start = s.begin();
        // trim leading whitespace
        while (*start == ' ') start++;

        bool isNeg = false;
        if (*start == '-') {
            isNeg = !isNeg;
            start++;
        } else if (*start == '+') start++;

        // 이제부터 숫자가 아닌 문자가 나올때 까지
        auto end = start;
        while (isDigit(end) && end != s.end()) {
            end++;
        }
        //end 는 문자이거나 문자열의 끝임

        //start를 0이아닌 숫자거나 end를 만날 때까지 증가
        while (*start == '0') start++;

        for (auto it = start; it != end; it++) {
            if(result > INT32_MAX/10 || (result == INT32_MAX/10 && *it > '7')){
                return isNeg ? INT32_MIN : INT32_MAX;
            }

            result = result * 10 + (*it-'0');
        }


        return isNeg ? result * (-1) : result;
    }
};