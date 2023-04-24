class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> operands = {"+","-","*","/"};
        for (auto &token: tokens) {
            if (operands.find(token) != operands.end()) {
                int op2 = stk.top();stk.pop();
                int op1 = stk.top();stk.pop();
                if (token == "+") {
                    stk.push(op1 + op2);
                } else if(token == "-") {
                    stk.push(op1 - op2);
                } else if(token == "*") {
                    stk.push(op1 * op2);
                } else {
                    stk.push(op1 / op2);
                }
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};