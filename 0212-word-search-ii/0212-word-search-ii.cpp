
class Solution {
private:
    struct Trie{
        unordered_map<char, Trie*> nexts;
        bool isEnd = false;
    } *root = new Trie();
    int m;
    int n;
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        m = board.size();
        n = board.front().size();
        unordered_set<string> result;

        buildTrie(words);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->nexts.find(board.at(i).at(j)) != root->nexts.end()) {
                    vector<vector<bool>> visited(m, vector<bool>(n));
                    dfs("", {i,j},board, visited, root, result);
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }

    void buildTrie(vector<string> &words){
        for(auto &word:words){
            auto node = root;
            for (int i = 0; i < word.length(); i++) {
                auto alphabet = word.at(i);
                if (node->nexts.find(alphabet) == node->nexts.end()) {
                    node->nexts[alphabet] = new Trie();
                }
                node = node->nexts[alphabet];
                if (i == word.length() - 1) {
                    node->isEnd = true;
                }
            }
        }
    }

    void dfs(string word, pair<int, int> position,vector<vector<char>> &board,
             vector<vector<bool>> &visited,Trie *node, unordered_set<string> &result) {
        if(node->isEnd){
            result.insert(word);
        }
        if (word.length() > 10) {
            return;
        }
        int x = position.first;
        int y = position.second;

        if (x < 0 || x == m || y < 0 || y == n || visited.at(x).at(y)) {
            return;
        }
        char alphabet = board.at(x).at(y);
        if (node->nexts.find(alphabet) == node->nexts.end()) {
            return;
        }
        visited.at(x).at(y) = true;
        auto next= node->nexts[alphabet];
        word += alphabet;

        dfs(word, {x + 1, y}, board, visited, next, result);
        dfs(word, {x - 1, y}, board, visited, next, result);
        dfs(word, {x, y + 1}, board, visited, next, result);
        dfs(word, {x, y - 1}, board, visited, next, result);

        if (next->nexts.empty()) {
            node->nexts.erase(alphabet);
        }
        word.pop_back();
        visited.at(x).at(y) = false;
    }
};