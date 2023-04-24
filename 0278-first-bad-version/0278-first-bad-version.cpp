class Solution {
public:
    int firstBadVersion(int n) {
        long s, m, e;
        s = 1;
        e = n;
        while (s < e) {
            m = (s + e) / 2;
            bool mid = isBadVersion(m);

            if (mid) {
                // push end to left
                e = m;
            } else {
                // push start to right
                s = m + 1;
            }
        }
        return (s+e)/2;
    }
};