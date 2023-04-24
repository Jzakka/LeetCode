
class Solution {
public:
    bool isPowerOfTwo(int n) {
//        cout << "log=" << log2(n) << "\n";
        if(n<=0) return false;
        int exp = log2(n);
        return n == pow(2, exp);
    }
};