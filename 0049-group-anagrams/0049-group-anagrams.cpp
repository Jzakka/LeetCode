class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> search;
        vector<vector<string >> result;
        for (auto& str: strs) {
            auto copied = str;
            std::sort(copied.begin(), copied.end());
            search[copied].push_back(str);
        }
        for (auto v: search) {
            result.emplace_back(v.second);
        }
        return result;
    }
};