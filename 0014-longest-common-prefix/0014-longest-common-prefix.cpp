class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        int least = accumulate(strs.begin(), strs.end(), INT32_MAX, [](int least, string e){
            least = least > e.length() ? e.length() : least;
            return least;
        });

        int idx = 0;
        while (idx<least){
            for (auto it = strs.begin(); it != prev(strs.end()); it++) {
                if(it->at(idx) != next(it)->at(idx)) return prefix;
            }
            prefix += (*strs.begin()).at(idx);
            idx++;
        }

        return prefix;
    }
};