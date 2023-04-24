class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        vector<string> temp(num2.length(), "");
        unsigned k = 0;
        for (int i = num2.length() - 1; i >= 0; i--, k++) {
            int carry = 0;

            for (int j = num1.length() - 1; j >= 0; j--) {
                int digit = num1.at(j) - '0';
                int mul = digit * (num2.at(i)-'0');
                int result = mul + carry;
                temp.at(i) =   (char) (result % 10 + '0') + temp.at(i);
                carry = result / 10;
            }
            if(carry) {
                temp.at(i) = (char) (carry + '0') + temp.at(i);
            }
            for (unsigned t = 0; t < k; t++) {
                temp.at(i) += '0';
            }
        }

        string res = temp.at(0);
        for (int i = 1; i  < temp.size(); i++) {
            res = sum(res, temp.at(i));
        }

        return res;
    }

    string sum(string num1, string num2){
        if(num1.length() > num2.length()) swap(num1, num2);
        int diff = num2.length() - num1.length();
        while (diff--) {
            num1 = '0' + num1;
        }
        string res = "";
        int carry = 0;
        for (int i = num2.length()-1; i >= 0; i--) {
            int digit1 = num1.at(i) - '0';
            int digit2 = num2.at(i) - '0';
            int sum = digit1 + digit2 + carry;
            res = (char) (sum % 10 + '0') + res;
            carry = sum / 10;
        }
        if(carry){
            res = (char)(carry+'0') + res;
        }
        return res;
    }
};
