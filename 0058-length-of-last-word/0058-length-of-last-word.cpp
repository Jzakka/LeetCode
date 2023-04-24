class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        stack<int> res;
        for (auto it = s.begin(); it != s.end(); it++) {
            if(*it != ' '){
                len++;
            }
            else
            {
                res.push(len);
                len = 0;
            }
        }
        res.push(len);
        while (!res.empty() && res.top() == 0) {
            res.pop();
        }

        return res.empty() ? 0 : res.top();
    }
};