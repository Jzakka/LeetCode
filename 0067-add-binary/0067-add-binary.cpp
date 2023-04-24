class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            swap(a, b);
        }
        int aPoint = a.length() - 1;
        int bPoint = b.length() - 1;
        int carry = 0;
        string res = "";
        while (aPoint >= 0) {
            int aDigit = a.at(aPoint) - '0';
            int bDigit = b.at(bPoint) - '0';
            res = (char) ((aDigit + bDigit + carry) % 2 + '0') + res;
            carry = (aDigit + bDigit + carry) / 2;
            aPoint--;
            bPoint--;
        }
        while (bPoint >= 0) {
            int bDigit = b.at(bPoint) - '0';
            res = (char) ((bDigit + carry) % 2 + '0') + res;
            carry = (bDigit + carry) / 2;
            bPoint--;
        }
        if(carry) {
            res = (char)(carry+'0') + res;
        }
        return res;
    }
};