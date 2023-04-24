class Solution {
private:
    int DP[20];
public:
    int numTrees(int n) {
        for(int i=0;i<20;i++){DP[i]=-1;}
        return recursive(1, n);
    }

    int recursive(int start, const int end) {
        int cnt = end - start;
        if (cnt <= 0) {
            return 1;
        }
        if (DP[cnt] != -1) {
            return DP[cnt];
        }

        int res = 0;
        for (int i = start; i <= end; i++) {
            int left = recursive(start, i - 1);
            int right = recursive(i + 1, end);
            res += left * right;
        }
        DP[cnt] = res;
        return res;
    }
};
