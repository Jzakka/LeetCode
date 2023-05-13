class Solution {
public:
    struct Trie {
        int index = -1;
        unordered_map<char, Trie *> nextTries;
        vector<int> palindromeIndex;

        Trie() {};

        bool isWordEnd() {
            return index != -1;
        }
    };

    unordered_map<string, int> wordIndex;

    vector<string> words;

    vector<vector<int>> palindromePairs(vector<string> &words) {
        this->words = words;
        Trie *root = new Trie();

        for (int i = 0; i < words.size(); i++) {
            auto word = words.at(i);
            wordIndex[word] = i;
            buildReversedTrie(root, word, i);
        }

        vector<vector<int>> res;

        for (int i = 0; i < words.size(); i++) {
            auto prefix = root;
            string word = words.at(i);
            result(prefix, i, word, res);
        }

        return res;
    }

    void result(Trie *&prefix, int idx, string &word, vector<vector<int>> &res) {
        for (int i = 0; i < word.size() && prefix; i++) {
            char alphabet = word.at(i);

            if (prefix->isWordEnd() && prefix->index != idx && isPalindrome(word, i, word.size() - 1)) {
                res.push_back({idx, prefix->index});
            }
            prefix = prefix->nextTries[alphabet];
        }
        if (prefix) {
            for (const auto &palindromeIndex: prefix->palindromeIndex){
                if (palindromeIndex != idx) {
                    res.push_back({idx, palindromeIndex});
                }
            }
        }
    }

    bool isPalindrome(string& word, int start, int end) {
        int s = start;
        int e = end;

        while (s <= e) {
            if (word.at(s) != word.at(e)) {
                return false;
            }
            s++;
            e--;
        }

        return true;
    }

    void buildReversedTrie(Trie *reverseRoot, string &word, int idx) {
        Trie *node = reverseRoot;
        for (int i=word.size()-1;i>=0;i--) {
            char alphabet = word.at(i);

            if (isPalindrome(word, 0, i)) {
                node->palindromeIndex.push_back(idx);
            }

            if (node->nextTries.find(alphabet) == node->nextTries.end()) {
                node->nextTries[alphabet] = new Trie();
            }
            node = node->nextTries[alphabet];
        }
        node->index = idx;
        node->palindromeIndex.push_back(idx);
    }
};