class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> sequences;
        unordered_set<string> res;
        int i=0;
        for (; i + 10 <= s.length(); i++) {
            string extracted = s.substr(i, 10);
            if (sequences.find(extracted) != sequences.end()) {
                res.insert(extracted);
            }
            sequences.insert(extracted);
        }
        return vector<string>(res.begin(), res.end());
    }
};