class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (auto &c: s) {
            count[c]++;
        }
        for (auto &c: t) {
            count[c]--;
        }

        for (auto &p: count) {
            if (p.second) {
                return false;
            }
        }
        return true;
    }
};