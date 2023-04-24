class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned i,j;
        int ss,star;
        i = j = 0;
        ss = star = -1;
        while (i < s.length()) {
            if (j >= p.length() ||
                    !((s.at(i) == p.at(j) || p.at(j) == '?') || p.at(j) == '*')) {
                if(star == -1) return false;
                i = ++ss;
                j = star + 1;
            }
            else if (s.at(i) == p.at(j) || p.at(j) == '?') {
                i++;
                j++;
            } else if(p.at(j) == '*'){
                ss = i;
                star = j++;
            }
        }

        if (i == s.length() && j < p.length()) {
            for (; j < p.length(); j++) {
                if (p.at(j) != '*') {
                    return false;
                }
            }
            return true;
        }
        return true;
    }
};