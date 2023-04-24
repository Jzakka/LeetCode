class Solution {
private:
    unordered_map<string, bool> palindromeMap;
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        recursive(0, s, path, res);

        return vector<vector<string >>(res.begin(), res.end());
    }

    void recursive(int idx, string s, vector<string> &path, vector<vector<string>> &res) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            string extracted = s.substr(idx, i-idx + 1);
            if (extracted == "aa") {
                int a = 1;
            }
            if (isPalindrome(extracted)) {
                path.push_back(extracted);
                recursive(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        if (palindromeMap.find(s) != palindromeMap.end()) {
            return palindromeMap[s];
        }
        int len = s.length();
        vector<int> LPS(len * 2 + 1, 0);
        string dum = "|";
        for (auto &c: s) {
            dum += c;
            dum += '|';
        }

        int i;
        int r = 0, c = 0;
        for (i = 1; i < len * 2 + 1; i++) {
            if (i < r) {
                LPS[i] = min(r - i, LPS[2 * c - i]);
            }

            while (i - 1 - LPS[i] >= 0 && i + 1 + LPS[i] < len * 2 + 1
                   && dum[i + 1 + LPS[i]] == dum[i - 1 - LPS[i]]) {
                LPS[i]++;
            }

            if (LPS[i] > r) {
                c = i;
                r = c + LPS[c];
            }
        }

        palindromeMap[s] = LPS[len] == len;
        return palindromeMap[s];
    }
};