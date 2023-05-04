class Solution {
public:
    bool notContains(unordered_set<char>& charSet, string& comparand){
        for (const auto &letter: comparand){
            if (charSet.find(letter) != charSet.end()) {
                return false;
            }
        }
        return true;
    }

    int maxProduct(vector<string>& words) {
        int minLen = 0;

        for (int i = 0; i < words.size(); i++) {
            auto &word = words.at(i);
            int criterionLen = word.length();
            unordered_set<char> containingChars(word.begin(), word.end());
            for (int j = i + 1; j < words.size(); j++) {
                auto &comparand = words.at(j);
                int compareLen = comparand.length();
                if(criterionLen*compareLen > minLen && notContains(containingChars, comparand)) {
                    minLen = criterionLen * compareLen;
                }
            }
        }

        return minLen;
    }
};