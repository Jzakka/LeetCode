
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words(26, "-");
        unordered_map<string, char> wordToIdx;

        vector<string> splitWords;
        split(s, splitWords);

        int i = 0;
        for (auto &c: pattern) {
            if (i >= splitWords.size()) {
                return false;
            }

            auto word = splitWords.at(i);
            if (words.at(c - 'a') == "-" && wordToIdx.find(word) == wordToIdx.end()) {
                words.at(c - 'a') = word;
                wordToIdx[word] = c;
            } else if (!(words.at(c - 'a') == word &&
                         (wordToIdx.find(word) != wordToIdx.end() && wordToIdx[word] == c))) {
                return false;
            }

            i++;
        }

        if (i != splitWords.size()) {
            return false;
        }
        return true;
    }

    void split(string s, vector<string> &words) {
        int start = 0;
        int end = 1;
        for (; end < s.length(); end++) {
            if (s.at(end) == ' ') {
                words.push_back(s.substr(start, end - start));
                start = end + 1;
            }
        }
        words.push_back(s.substr(start, end - start));
    }
};