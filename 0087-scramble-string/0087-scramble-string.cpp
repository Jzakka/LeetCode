class Solution {
private:
    unordered_map<string, bool> DP;
public:
    bool isScramble(string s1, string s2) {
        string key = s1 + "|" + s2;
        if(DP.find(key) != DP.end()) {
            return DP[key];
        }
        if(s1 == s2) {
            DP[key] = true;
            return true;
        }
        int len = s1.length();
        if(len != s2.length()) {
            DP[key] = false;
            return false;
        }

        for (int i = 1; i < len; i++) {
            if (isScramble(first(i, s1), second(len-i, s2)) && isScramble(second(i, s1), first(len-i, s2))) {
                DP[key] = true;
                return true;
            }
            if (isScramble(first(i, s1), first(i, s2)) && isScramble(second(i, s1), second(i, s2))) {
                DP[key] = true;
                return true;
            }
        }

        DP[key] = false;
        return false;
    }

    string first(int cut, const string& str) {
        return str.substr(0, cut);
    }

    string second(int cut, const string& str){
        return str.substr(cut, str.length());
    }
};