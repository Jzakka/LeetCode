class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto &word: wordDict) {
            wordSet.insert(word);
        }
        vector<string> sentences;

        splitable(sentences, wordSet, s, 0, "");

        return sentences;
    }

    void splitable(vector<string> &sentences,unordered_set<string> &wordSet,
                   string s, int start, string sentence) {
        for (int cut = start + 1; cut <= s.length(); cut++) {
            string extracted = s.substr(start, cut - start);
            if (wordSet.find(extracted) != wordSet.end()) {
                splitable(sentences, wordSet, s, cut, sentence + extracted + (cut == s.length() ? "" :" "));
            }
        }
        if (start == s.length()) {
            sentences.push_back(sentence);
        }
    }
};