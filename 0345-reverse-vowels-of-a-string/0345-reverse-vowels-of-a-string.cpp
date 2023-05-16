class Solution {
public:
    unordered_set<char> vowels = {
            'a','e','i','o','u',
            'A','E','I','O','U',};

    string reverseVowels(string s) {
        vector<int> vowelIndices;
        for (int i=0;i<s.length();i++){
            char alphabet = s.at(i);
            if (vowels.find(alphabet) != vowels.end()) {
                vowelIndices.push_back(i);
            }
        }

        int begin, end;
        begin = 0;
        end = vowelIndices.size() - 1;

        while (begin < end) {
            swap(s.at(vowelIndices.at(begin++)), s.at(vowelIndices.at(end--)));
        }
        return s;
    }
};