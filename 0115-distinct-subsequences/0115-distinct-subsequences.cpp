class Solution {
private:
    map<pair<int, int>, int> DP;
public:
    int numDistinct(string s, string t) {
        return recursive(s, t, 0, 0, 0);
    }

    int recursive(const string &s, const string &t,
                  int idx1, int idx2, int cnt) {
//        cout << "\n" << idx1 << ":" << idx2;
        if (DP.find({idx1, idx2}) != DP.end()) {
            return DP[{idx1, idx2}];
        }
        int res;
        if (idx2 >= t.length()) {
            cnt++;
            res = cnt;
        } else if (idx1 >= s.length()) {
            res = cnt;
        } else if (s.at(idx1) == t.at(idx2)) {
            res = recursive(s, t, idx1 + 1, idx2 + 1, cnt)
                  + recursive(s, t, idx1 + 1, idx2, cnt);
        } else {
            res = recursive(s, t, idx1 + 1, idx2, cnt);
        }
        DP[{idx1, idx2}] = res;
        return res;
    }
};