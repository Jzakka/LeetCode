// 2387299
// 2*3+8*7*2+9+9
// 2                    -> 2                                        , prev = 2
// 2*3                  -> 2 - prev + prev*3=6                      , prev = 6
// 2*3 + 8              -> 6 + 8 = 14                               , prev = 8
// 2*3 + 8*7            -> 14 - prev + prev*7=62                    , prev = 56
// 2*3 + 8*7*2          -> 62 - prev + prev*2=118                   , prev = 112
// 2*3 + 8*7*2 + 9      -> 118 + 9 = 127                            , prev = 9
// 2*3 + 8*7*2 + 9 + 9  -> 127 + 9 = 136                            , prev = 9
class Solution {
private:
    vector<string> answer;
    string digits;
    long target;
public:
    vector<string> addOperators(string num, int target) {
        if (num.length() == 0) {
            return {};
        }
        digits = num;
        this->target = target;
        vector<string> ops;
        recursive(0, 0, 0, 0, ops);
        return answer;
    }
    void recursive(int idx, long prevNum, long curNum, long val, vector<string>& ops) {
        if (idx >= digits.length()) {
            if (val == target && curNum == 0) {
                string res = "";
                for (auto it = ops.begin()+1;it!=ops.end();it++) {
                    res.append(*it);
                }
                answer.push_back(res);
            }
            return;
        }
        curNum = curNum * 10 + digits.at(idx) - '0';
        string curNumStr = to_string(curNum);
        //nop
        if (curNum > 0) {
            recursive(idx + 1, prevNum, curNum, val, ops);
        }

        //cut now
        // +
        ops.emplace_back("+");
        ops.push_back(curNumStr);
        recursive(idx + 1, curNum, 0, val + curNum, ops);
        ops.erase(ops.end() - 2, ops.end());

        if (ops.size() > 0) {
            // -
            ops.emplace_back("-");
            ops.push_back(curNumStr);
            recursive(idx + 1, -curNum, 0, val - curNum, ops);
            ops.erase(ops.end() - 2, ops.end());

            // *
            ops.emplace_back("*");
            ops.push_back(curNumStr);
            recursive(idx + 1, prevNum*curNum, 0, val - prevNum + prevNum*curNum, ops);
            ops.erase(ops.end() - 2, ops.end());
        }
    }
};

// 공식 풀이 참조함
// 공식풀이 씨발 ㅈㄴ어렵게 풀어놨네. 마지막 항을 재귀 종료조건으로 처리하는건 뭐야 애미