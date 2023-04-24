
class WordDictionary {
private:
    struct Node {
        unordered_map<char, Node *> nexts;
        bool isEnd = false;
    };
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        auto node = root;
        for (int i = 0;i<word.length();i++) {
            char alphabet = word.at(i);
            if (node->nexts.find(alphabet)==node->nexts.end()) {
                node->nexts[alphabet] = new Node;
            }
            node = node->nexts[alphabet];
            if (i == word.length() - 1) {
                node->isEnd = true;
            }
        }
    }

    bool search(string word) {
        auto node = root;
        return dfs(0, node, word);
    }

    bool dfs(int pos, Node *node, string word) {
        int wdLen = word.length();
        if (pos == wdLen) {
            return node->isEnd;
        }
        char alphabet = word.at(pos);
        if (alphabet == '.') {
            for (auto &next: node->nexts) {
                if (dfs(pos + 1, next.second, word)) {
                    return true;
                }
            }
            return false;
        }
        if (node->nexts.find(alphabet) == node->nexts.end()) {
            return false;
        }
        return dfs(pos + 1, node->nexts[alphabet], word);
    }
};