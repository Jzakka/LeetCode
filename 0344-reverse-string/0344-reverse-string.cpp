class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin, end;
        begin = 0;
        end = s.size() - 1;
        while (begin < end) {
            swap(s.at(begin++), s.at(end--));
        }
    }
};