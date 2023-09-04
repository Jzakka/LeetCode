class Solution {
public:
    string longestPalindrome(string word) {
        string extended = "";

    for (int i = 0; i < word.length() * 2 + 1; i++) {
        if (i & 1) {
            extended += word.at(i/2);
        } else {
            extended += '#';
        }
    }

    vector<int> lps(extended.length(), 0);

    int r = 0;
    int c = 0;
    int len = extended.length();
    for (int i = 1; i < len; i++) {
        if (i < r) {
            lps.at(i) = min(r - i, lps.at(2 * c - i));
        }

        while (i - 1 - lps.at(i) >= 0 && i + 1 + lps.at(i) < len
               && extended.at(i - 1 - lps.at(i)) == extended.at(i + 1 + lps.at(i))) {
            lps.at(i)++;
        }

        if (lps.at(i) + i > r) {
            c = i;
            r = c + lps.at(c);
        }
    }

    int maxLen = -1;
    int idx = 0;

    for (int i = 0; i < lps.size(); i++) {
        if (lps.at(i) > maxLen) {
            maxLen = lps.at(i);
            idx = i;
        }
    }

    string res = "";
    for (int i = idx - maxLen; i < idx + maxLen; i++) {
        if (extended.at(i) != '#') {
            res += extended.at(i);
        }
    }
    return res;
    }
};