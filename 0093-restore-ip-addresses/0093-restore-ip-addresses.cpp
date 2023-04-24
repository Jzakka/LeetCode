class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        string buildingAddress = "";
        recursive(s, 0, 0, buildingAddress);
        return res;
    }

    void recursive(const string &s, int cur, int cnt, string buildingAddress) {
        if (cnt == 4) {
            if (cur == s.length()) {
                res.push_back(buildingAddress);
            }
            return;
        }

        if (cur < s.length()) {
            string oneBit = s.substr(cur, 1);
            if (validate(oneBit)) {
                recursive(s, cur + 1, cnt + 1, buildingAddress + oneBit + (cnt== 3 ? "" : "."));
            }
            if (cur + 1 < s.length()) {
                string twoBits = s.substr(cur, 2);
                if (validate(twoBits)) {
                    recursive(s, cur + 2, cnt + 1, buildingAddress + twoBits + (cnt== 3 ? "" : "."));
                }
                if (cur + 2 < s.length()) {
                    string threeBits = s.substr(cur, 3);
                    if (validate(threeBits)) {
                        recursive(s, cur + 3, cnt + 1, buildingAddress + threeBits + (cnt== 3 ? "" : "."));
                    }
                }
            }
        }
    }

    bool validate(string& bits){
        int num = stoi(bits);
        if(bits.length()>1 && bits.front() == '0') return false;
        return 0 <= num && num <= 255;
    };
};