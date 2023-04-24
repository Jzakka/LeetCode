class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;

        for (auto it = s.begin(); it != s.end(); it++) {
            char poped;
            switch (*it) {
                case '(':
                    paren.push('(');
                    break;
                case '[':
                    paren.push('[');
                    break;
                case '{':
                    paren.push('{');
                    break;
                case ')':
                    if(paren.empty()) return false;
                    poped = paren.top();
                    paren.pop();

                    if(poped!='(')
                        return false;
                    break;
                case ']':
                    if(paren.empty()) return false;
                    poped = paren.top();
                    paren.pop();

                    if(poped!='[')
                        return false;
                    break;
                case '}':
                    if(paren.empty()) return false;
                    poped = paren.top();
                    paren.pop();

                    if(poped!='{')
                        return false;
                    break;
            }
        }

        return paren.empty();
    }
};