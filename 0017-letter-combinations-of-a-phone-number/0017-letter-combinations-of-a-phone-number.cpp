class Solution {
private:
    map<int, vector<char> > buttons;

public:
    Solution() {
        buttons[2] = {'a', 'b', 'c'};
        buttons[3] = {'d', 'e', 'f'};
        buttons[4] = {'g', 'h', 'i'};
        buttons[5] = {'j', 'k', 'l'};
        buttons[6] = {'m', 'n', 'o'};
        buttons[7] = {'p', 'q', 'r', 's'};
        buttons[8] = {'t', 'u', 'v'};
        buttons[9] = {'w', 'x', 'y', 'z'};
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;

        return append(result, digits, 0);
    }

    vector<string> append(vector<string> &vec, string digits, int pos) {
        if (pos >= digits.length()) {
            return vec;
        }

        vector<string > res;
        auto chars = buttons[digits.at(pos) - '0'];
        if (vec.empty()) {
            for (auto c: chars) {
                res.push_back(string(1,c));
            }
        } else {
            for (auto c: chars) {
                for (auto s: vec) {
                    res.push_back(s + c);
                }
            }
        }
        return append(res,digits,pos+1);
    }
};