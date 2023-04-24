class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        unsigned strLen = s.length();
        stack<int> pos;
        pos.push(-1);

        for (unsigned i = 0; i < strLen; i++) {
            if (s.at(i) == '(') {
                pos.push(i);
            } else if (pos.size() > 1) {
                pos.pop();
                int start = pos.top();

                int len = i - start;
                if (maxLen < len) maxLen = len;
            } else {
                pos.top() = i;
            }
        }

        return maxLen;
    }
};