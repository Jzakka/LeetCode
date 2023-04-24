class Solution {
private:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> adjacentList;
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> parents;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        std::for_each(wordList.begin(), wordList.end(), [this](auto &word) {
            wordSet.insert(word);
        });
        build(beginWord, wordList);
        BFS(beginWord, endWord, wordList);

        vector<string> path = {endWord};
        findPaths(path, beginWord, endWord);
        for (auto &vec: res) {
            std::reverse(vec.begin(), vec.end());
        }

        return res;
    }

    void findPaths(vector<string> &path,const string& start,const string& cur) {
        if (cur == start) {
            res.push_back(path);
            return;
        }

        for (auto &par: parents[cur]) {
            path.push_back(par);
            findPaths(path, start, par);
            path.pop_back();
        }
    }

    void BFS(string start, string end, vector<string> &wordList) {
        unordered_map<string, int> dist;
        std::for_each(wordList.begin(), wordList.end(), [&dist](const auto &word) {
            dist[word] = INT32_MAX;
        });

        queue<string> Q;

        Q.push(start);
        parents[start] = {"-1"};
        dist[start] = 0;

        while (!Q.empty()) {
            string cur = Q.front();
            Q.pop();
            for (auto &adjacent: adjacentList[cur]) {
                if (dist[adjacent] > dist[cur] + 1) {
                    dist[adjacent] = dist[cur] + 1;
                    Q.push(adjacent);
                    parents[adjacent].clear();
                    parents[adjacent].push_back(cur);
                } else if (dist[adjacent] == dist[cur] + 1) {
                    parents[adjacent].push_back(cur);
                }
            }
        }
    }

    void build(string begin, vector<string> &wordList) {
        for (int i = 0; i < begin.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string copied = begin;
                copied.at(i) = c;
                if (copied != begin && wordSet.find(copied) != wordSet.end()) {
                    adjacentList[begin].push_back(copied);
                }
            }
        }
        for (auto &word: wordList) {
            if (word == begin) {
                continue;
            }
            for (int i = 0; i < word.length(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string copied = word;
                    copied.at(i) = c;
                    if (copied != word && wordSet.find(copied) != wordSet.end()) {
                        adjacentList[word].push_back({copied, false});
                    }
                }
            }
        }
    }
};