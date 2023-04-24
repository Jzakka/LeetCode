class Solution {
public:
    string reverseWords(string s) {
        while (s.front() == ' ') {
            s.erase(s.begin());
        }
        while (s.back() == ' ') {
            s.erase(s.end() - 1);
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ' ' && s[i - 1] == ' ') {
                s.erase(s.begin() + i);
                i--;
            }
        }
        s= " " + s;


        int i = 1;
        while (i < s.length()) {
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            int start = i;
            int end = start + 1;
            while (end < s.length() && s[end] != ' ') {
                end++;
            }
            int wordLen = end - start;
            string word = s.substr(start, wordLen);
            s.erase(start, wordLen);
            s = word + s;
            i = start + wordLen;
        }
        s.erase(0, 1);
        return s;
    }
};