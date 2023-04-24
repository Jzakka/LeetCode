class Solution {
public:
    double myPow(double x, int n) {
        long e = n;
        if (e < 0) {
            return 1/recursivePow(x, -e);
        }
        return recursivePow(x, e);
    }

    double recursivePow(double x, unsigned e){
        if (e == 0 || x == 1) {
            return 1;
        }
        unsigned partialE = e / 2;
        double part = recursivePow(x, partialE);
        if(e&1) return part * part * x;
        return part * part;
    }
};