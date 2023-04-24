class Solution {
public:
    int romanToInt(string s) {
        auto it = s.begin();
        int result = 0;

        while (it != s.end()) {
            switch (*it) {
                case 'I':
                    if(*next(it)=='V'||*next(it)=='X')
                        result--;
                    else
                        result++;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    if(*next(it)=='L'||*next(it)=='C')
                        result-=10;
                    else
                        result+=10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    if(*next(it)=='D'||*next(it)=='M')
                        result-=100;
                    else
                        result+=100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
                default:
                    break;
            }
            it++;
        }
        return result;
    }
};