class Solution {
private:
    map<tuple<int,int,int>, bool> DP;
public:
    bool isInterleave(string s1, string s2, string s3) {
        return recursive(s1, s2, s3, 0, 0, 0);
    }

    bool recursive(string s1, string s2, string s3, int idx1, int idx2, int idx3) {
        if (DP.find({idx1, idx2, idx3}) != DP.end()) {
            return DP[{idx1, idx2, idx3}];
        }
        if (idx3 >= s3.length() && idx2 >= s2.length() && idx1 >= s1.length()) {
            return true;
        }

        bool match1 = idx1 >= s1.length() ? false : s1[idx1] == s3[idx3];
        bool match2 = idx2 >= s2.length() ? false : s2[idx2] == s3[idx3];

        if (!match1 && !match2) {
            DP[{idx1, idx2, idx3}] = false;
            return false;
        } else if (match1 && !match2) {
            DP[{idx1, idx2, idx3}] = recursive(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
            return DP[{idx1, idx2, idx3}];
        } else if (!match1 && match2) {
            DP[{idx1, idx2, idx3}] = recursive(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
            return DP[{idx1, idx2, idx3}];
        } else {
            DP[{idx1, idx2, idx3}] = recursive(s1, s2, s3, idx1 + 1, idx2, idx3 + 1)
                                     || recursive(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
            return DP[{idx1, idx2, idx3}];
        }
    }
};