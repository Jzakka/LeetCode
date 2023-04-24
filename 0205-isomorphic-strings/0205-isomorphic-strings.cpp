
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> sourceToDest(INT16_MAX, NULL);
        vector<char> destToSource(INT16_MAX, NULL);

        int strLen = s.length();
        for (int i = 0; i < strLen; i++) {
            char srcChar = s.at(i);
            char destChar = t.at(i);
            if (destToSource.at(destChar) == NULL) {
                if (sourceToDest.at(srcChar) == NULL) {
                    sourceToDest.at(srcChar) = destChar;
                    destToSource.at(destChar) = srcChar;
                } else {
                    return false;
                }
            } else if (destToSource.at(destChar) != srcChar) {
                return false;
            }
        }
        return true;
    }
};