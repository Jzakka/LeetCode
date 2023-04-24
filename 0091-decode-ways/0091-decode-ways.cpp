class Solution {
private:
    unordered_set<string> twoBits = {
            "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
            "20", "21", "22", "23", "24", "25", "26"
    };
    unordered_map<string, int> strInt = {
            {"", 1},{"0",0},
            {"1", 1},{"2", 1},{"3", 1},{"4", 1},{"5", 1},
            {"6", 1},{"7", 1},{"8", 1},{"9", 1},{"10", 1},
            {"11", 2},{"12", 2},{"13", 2},{"14", 2},{"15", 2},{"16", 2},
            {"17", 2},{"18", 2},{"19", 2},{"20", 1},{"21", 2},{"22", 2},
            {"23", 2},{"24", 2},{"25", 2},{"26", 2}
    };
public:
    int numDecodings(string s) {
        return recursive(s);
    }

    int recursive(const string &s) {
        if (strInt.find(s) != strInt.end()) {
            return strInt[s];
        }

        int strLen = s.length();
        int mid = strLen / 2;

        string left = s.substr(0, mid);
        string right = s.substr(mid, strLen);
        int leftCnt = recursive(left);
        int rightCnt = recursive(right);
        int cnt = leftCnt * rightCnt;
        // 중간에 걸치는 경우
        int mid2Left = mid - 1;
        int mid2Right = mid + 1;
        if (mid2Left >= 0) {
            string medium = s.substr(mid2Left, 2);
            if (twoBits.find(medium) != twoBits.end()) {
                string left2 = s.substr(0, mid2Left);
                string right2 = s.substr(mid2Right, strLen);
                int leftCnt2 = recursive(left2);
                int rightCnt2 = recursive(right2);
                cnt += leftCnt2 * rightCnt2;
            }
        }
        strInt[s] = cnt;
        return cnt;
    }
};