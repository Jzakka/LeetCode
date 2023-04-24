class Solution {
public:
    bool isPalindrome(string s) {
        string converted = "";
        for (auto &c: s) {
            if (('a' <= c && c <= 'z') || ('0' <= c && c<= '9')) {
                converted += c;
            } else if ('A' <= c && c <= 'Z') {
                converted += (c - ('A' - 'a'));
            }
        }
        string copied = converted;
        std::reverse(copied.begin(), copied.end());
        return copied == converted;
    }
};