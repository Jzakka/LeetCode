class Solution {
public:
    bool signSideValidation(int idx, const string &s){
        if(s.length() == 1) return false;
        char right;
        char left;
        if (idx == 0) {
            right = s.at(idx + 1);
            if (right == '.' || (right >= '0' && right <= '9')) return true;
        } else if (idx == s.length() - 1) {
            return false;
        } else {
            left = s.at(idx - 1);
            if(left == 'e' || left == 'E') return true;
        }

        return false;
    }

    bool dotSideValidation(int idx, const string &s) {
        if (s.length() == 1) return false;
        char right;
        char left;
        if (idx == 0) {
            right = s.at(idx + 1);
            if (right >= '0' && right <= '9') return true;
        } else if (idx == s.length() - 1) {
            left = s.at(idx - 1);
            if (left >= '0' && left <= '9') return true;
        } else {
            right = s.at(idx + 1);
            left = s.at(idx - 1);
            if ((right >= '0' && right <= '9') || (left >= '0' && left <= '9')) return true;
        }

        return false;
    }

    bool isNumber(string s) {
        bool decimal = true;
        bool decimalSign = false;
        bool integer = false;
        bool integerSign = false;
        bool dot = false;

        int idx = 0;
        for (auto &c: s) {
            switch (c) {
                case '-':
                case '+':
                    if (idx == s.length() - 1 || !signSideValidation(idx, s))
                        return false;
                    if (s.length() == 1 || decimal) {
                        if (decimalSign || idx != 0) return false;
                        decimalSign = true;
                    } else {
                        if (integerSign || (s.at(idx - 1) != 'e' && s.at(idx - 1) != 'E')) return false;
                        integerSign = true;
                    }
                    break;
                case 'e':
                case 'E':
                    if (idx == s.length() - 1 || idx == 0 || integer) return false;
                    decimal = false;
                    integer = true;
                    break;
                case '.':
                    if (!dotSideValidation(idx, s)) return false;
                    if (s.length() == 1 || integer || dot) return false;
                    dot = true;
                    break;
                default:
                    if (c < '0' || c > '9') return false;
                    break;
            }
            idx++;
        }
        return true;
    }
};