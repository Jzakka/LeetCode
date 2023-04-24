class Solution {
public:
    std::vector<std::vector<bool>> palindromes;

    bool iterativeCheck(std::string &s, int i, int k) {
        for (int start = i, last = k; start < last; start++, last--) {
            if (palindromes[start][last])
                break;
            else if(s.at(start)!=s.at(last))
                return false;
        }
        palindromes[i][k] = true;
        return true;
    }

    /*bool recursiveCheck(std::string &s, int i, int k) {
        if (i >= k) {
            palindromes[i][k] = true;
            return true;
        }
        if (palindromes[i][k])
            return true;
        else if (s.at(i) == s.at(k)) {
            bool isSubStrPalindrome = recursiveCheck(s, i + 1, k - 1);
            if(isSubStrPalindrome)   {
                palindromes[i, k];
                return true;
            }
        }
        return false;
    }*/

    std::string longestPalindrome(std::string s) {
        unsigned long strLen = s.length();
        palindromes = std::vector<std::vector<bool>>(strLen, std::vector<bool>(strLen, false));
        std::string maxPal = "";

        for (int diff = 0; diff < strLen; diff++) {
            int start = 0;
            while (start + diff < strLen) {
                if (s.at(start) == s.at(start + diff) && iterativeCheck(s, start, start +diff)) {
                    unsigned long maxLen = maxPal.length();
                    if(maxLen <diff+1) maxPal = s.substr(start, diff+1);
                }
                start++;
            }
        }

        return maxPal;
    }
};