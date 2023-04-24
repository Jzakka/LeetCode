class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        vector<bool> DP(301, true);
        for (auto &word: wordDict) {
            wordSet.insert(word);
        }

        return splitable(DP, wordSet, s, 0);
    }

    bool splitable(vector<bool>& DP, unordered_set<string> &wordSet, string s, int start) {
        for (int cut = start + 1; cut <= s.length(); cut++) {
            if (wordSet.find(s.substr(start, cut - start)) != wordSet.end()
                && DP[cut]
                && splitable(DP, wordSet, s, cut)) {
                return true;
            }
        }
        DP[start] = start == s.length();
        return start == s.length();
    }
};