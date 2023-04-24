class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        int s, m, e;
        s = 0;
        e = len - 1;

        while (s < e) {
            m = (s + e) / 2;
            if (isHIndex(m, len, citations) >= 0) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        m = (s + e) / 2;

        return isHIndex(m, len, citations) >= 0 ? len - m : 0;
    }

    int isHIndex(int idx, int len, vector<int> &citations) {
        int h = len - idx;
        int num = citations.at(idx);
        return num == h ? 0 : num < h ? -1 : 1;
    }
};

// 0 1 3 5 6
// h == 5 -> (5 - 5)번째가 5 이상인가?  : 반으로 줄이기
// h == 2 -> (5 - 2)번째가 2 이상인가? 정답 : 