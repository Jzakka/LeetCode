class Solution {
private:
    vector<int> codes;
public:
    vector<int> grayCode(int n) {
        codes = vector<int>(pow(2,n));
        recursive(n);
        return codes;
    }

    void recursive(int n) {
        if (n == 1) {
            codes[0] = 0;
            codes[1] = 1;
            return;
        }
        recursive(n - 1);
        int start = pow(2, n - 1);
        int end = pow(2, n);
        for (int i = start; i < end; i++) {
            codes[i] = codes[end - i - 1] + start;
        }
    }
};