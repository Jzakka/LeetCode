class Solution {
private:
    unordered_set<string> wordSet;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::for_each(wordList.begin(), wordList.end(),[this](const auto& word){
            wordSet.insert(word);
        });

        return BFS(beginWord, endWord);
    }
    int BFS(string start, string end){
        queue<string> Q;
        int len = 0;
        Q.push(start);
        while (!Q.empty()) {
            int qLen = Q.size();
            len++;
            for (int i = 0; i < qLen; i++) {
                string cur = Q.front();
                if (cur == end) {
                    return len;
                }
                wordSet.erase(cur);
                Q.pop();
                for (int i = 0; i < cur.length(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        string copied = cur;
                        copied.at(i) = c;
                        if (copied != cur && wordSet.find(copied) != wordSet.end()) {
                            Q.push(copied);
                        }
                    }
                }
            }
        }
        return 0;
    }
};