#define CONVERTED_LENGTH strLen*2 + 1

class Solution {
private:
    int strLen;
    vector<int> LPS;
    string converted = "|";
public:
    string shortestPalindrome(string s) {
        init(s);
        fillLPS(s);
        return getPrefix(getCutPoint()) + s;
    }

    void init(string s){
        strLen = s.length();
        LPS = vector<int>(strLen+1, 0);
        converted = convert(s);
    }

    string convert(string s){
        std::for_each(s.begin(), s.end(), [this](auto &letter) {
            converted += letter;
            converted += '|';
        });
        return converted;
    }

    void fillLPS(string s) {
        int rightEnd = 0, center = 0;

        for (int i = 0; i <= strLen; i++) {
            if (i < rightEnd) {
                LPS.at(i) = min(rightEnd - i, LPS.at(2*center - i));
            }

            while ((i - 1 - LPS.at(i) >= 0 && i + 1 + LPS.at(i) < CONVERTED_LENGTH)
                   && converted.at(i - 1 - LPS.at(i)) == converted.at(i + 1 + LPS.at(i))) {
                LPS.at(i)++;
            }

            if (LPS.at(i)+i > rightEnd) {
                center = i;
                rightEnd = center + LPS.at(center);
            }
        }
    }

    int getCutPoint(){
        for (int i = strLen; i >= 0; i--) {
            if (i - LPS.at(i) == 0) {
                return i + LPS.at(i);
            }
        }
        return -1;
    }

    string getPrefix(int cutPoint){
        string result;
        string extracted = converted.substr(cutPoint, CONVERTED_LENGTH - cutPoint);
        std::copy_if(extracted.begin(), extracted.end(), back_inserter(result), [](auto & letter){
            return letter != '|';
        });
        std::reverse(result.begin(), result.end());
        return result;
    }
};