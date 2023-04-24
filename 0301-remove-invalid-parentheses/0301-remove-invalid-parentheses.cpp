class Solution {
private:
    unordered_set<string> minValid;
    stack<byte> stk;

    void recursive(int idx, string building, const string &s){
        if (idx >= s.length()) {
            if (stk.empty()) {
                minValid.insert(building);
            }
            return;
        }
        if(s.at(idx) == '('){
            // 추가한다
            stk.push((byte) 1);
            recursive(idx + 1, building + '(', s);
            stk.pop();
            // 추가 안한다
            recursive(idx + 1, building, s);
        } else if (s.at(idx) == ')') {
            //이걸 추가했을 때 무효한 괄호라면 추가 안함
            if (!stk.empty()) {
                stk.pop();
                recursive(idx + 1, building + ')', s);
                stk.push((byte)1);
                recursive(idx + 1, building, s);
            } else {
                recursive(idx + 1, building, s);
            }
        } else {
            //select
            recursive(idx + 1, building + s.at(idx), s);
        }
    }
public:

    vector<string> removeInvalidParentheses(string s) {
        recursive(0, "",s);
        vector<string> res;
        res.insert(res.end(), minValid.begin(), minValid.end());
        int maxLen = 0;
        for (auto &a: res) {
            maxLen = max(maxLen, (int)a.size());
        }
        vector<string> filtered;
        std::copy_if(res.begin(), res.end(), back_inserter(filtered),
                     [maxLen](string str){return str.length()==maxLen;});
        return filtered;
    }
};