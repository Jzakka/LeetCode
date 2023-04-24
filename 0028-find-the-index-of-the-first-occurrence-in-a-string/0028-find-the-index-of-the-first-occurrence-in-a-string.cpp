
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        vector<int> F = failureFunc(needle);
        int i = 0;
        int j = 0;
        while (i < n) {
            if (haystack.at(i) == needle.at(j)) {
                if (j == needle.length() - 1)
                    return i - j;
                i++;
                j++;
            } else if (j > 0) {
                j = F[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }

    vector<int> failureFunc(string needle) {
        int m = needle.length();
        vector<int> F(m,0);
        int i = 1;
        int j = 0;
        while (i < m) {
            if (needle.at(i) == needle.at(j)) {
                F[i] = j + 1;
                i++;
                j++;
            } else if (j > 0) {
                j = F[j - 1];
            } else {
                F[i++] = 0;
            }
        }

        return F;
    }
};