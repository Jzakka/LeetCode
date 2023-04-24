class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> results;

        bool isNumber = true;

        for (int i = 0; i < expression.length(); i++) {
            if (isOp(expression.at(i))) {
                isNumber = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.length()));

                for (auto lVal: left) {
                    for (auto rVal: right) {
                        results.push_back(calc(lVal, expression.at(i), rVal));
                    }
                }
            }
        }
        if (isNumber) {
            results.push_back(stoi(expression));
        }

        return results;
    }

    bool isOp(char letter){
        return letter == '+' || letter == '-' || letter == '*';
    }

    int calc(int left, char op, int right){
        switch (op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            default:
                return -1;
        }
    }
};