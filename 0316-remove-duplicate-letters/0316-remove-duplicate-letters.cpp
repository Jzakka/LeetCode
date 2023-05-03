class Solution {
public:
    struct CharIdx {
        char letter;
        vector<int> indices;

        CharIdx(char letter) : letter(letter) {}
    };

    bool isFarLeft(map<char, vector<int>> &indices, int idx) {
        for (const auto &index: indices) {
            if (idx > index.second.back()) {
                return false;
            }
        }
        return true;
    }

    pair<char, int> rotate(map<char, vector<int>> &indices, int curIdx) {
        for (auto it = indices.begin(); it != indices.end(); it++) {
            int idx = *std::lower_bound(it->second.begin(), it->second.end(), curIdx);

            if (isFarLeft(indices, idx)) {
                return {it->first, idx};
            }
        }
        return {'E', -1};
    }

    string removeDuplicateLetters(string s) {
        map<char, vector<int>> indices;
        for (int i = 0; i < s.size(); i++) {
            char letter = s.at(i);
            indices[letter].push_back(i);
        }

        string res;
        int curIdx = 0;
        while (!indices.empty()) {
            pair<char, int> result = rotate(indices, curIdx);
            char appendLetter = result.first;
            curIdx = result.second;
            res += appendLetter;
            indices.erase(appendLetter);
        }

        return res;
    }
};