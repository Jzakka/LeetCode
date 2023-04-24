class Solution {
private:
    set<tuple<int,int,int>> tupleSet;
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) {
            return false;
        }
        if (num == "000") {
            return true;
        }

        int s = 0;
        int m = 1;
        int e = 2;

        while (m+1 < num.length() && (num.at(m) == '0' && num.at(m+1) == '0')) {
            m++;
            e = m + 1;
        }
        if (e == num.length()) {
            return false;
        }

        return recursive(num, s, m, e);
    }

    bool recursive(string num, int s, int m, int e) {
        if (tupleSet.find({s, m, e}) != tupleSet.end()) {
            return false;
        }
        if (e == num.length()) {
            return true;
        }
        if (num.at(m) == '0' && num.at(m + 1) == '0') {
            return false;
        }

        string left = num.substr(s, m - s);
        string right = num.substr(m, e - m);
        string expect = sum(left, right);

        if (e + expect.length() <= num.length() && num.substr(e, expect.length()) == expect
            && recursive(num, m, e, e + expect.length())) {
            return true;
        }

        int nextEnd = e + 1;
        while (nextEnd + 1 < num.length() && !recursive(num, s, m, nextEnd)) {
            nextEnd++;
        }
        if (nextEnd+1 < num.length() && tupleSet.find({s, m, nextEnd}) == tupleSet.end()) {
            return true;
        }
        int nextMid = m + 1;
        while (nextMid + 2 <= num.length() && !recursive(num, s, nextMid, nextMid + 1)) {
            nextMid++;
        }
        if (nextMid+2<=num.length() && tupleSet.find({s, nextMid, nextMid+1}) == tupleSet.end()) {
            return true;
        }
        tupleSet.insert({s, m, e});
        return false;
    }

    string sum(string num1, string num2) {
        stack<char> stk;

        int carry = 0;
        int i = 0;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (; i < num1.length() && i < num2.length(); i++) {
            int digit1 = num1.at(i) - '0';
            int digit2 = num2.at(i) - '0';
            int addition = digit1 + digit2 + carry;
            stk.push(addition % 10 + '0');
            carry = addition / 10;
        }

        while (i < num1.length()) {
            int digit1 = num1.at(i) - '0';
            int addition = digit1 + carry;
            stk.push(addition % 10 + '0');
            carry = addition / 10;
            i++;
        }

        while (i < num2.length()) {
            int digit2 = num2.at(i) - '0';
            int addition = digit2 + carry;
            stk.push(addition % 10 + '0');
            carry = addition / 10;
            i++;
        }

        if (carry) {
            stk.push('1');
        }

        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};