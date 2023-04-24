class Solution {
public:
    int hIndex(vector<int> &citations) {
        unsigned long len = citations.size();
        std::sort(citations.begin(), citations.end());
        int h;
        for (h = len; h >= 1; h--) {
            if (citations.at(len - h) >= h) {
                break;
            }
        }
        return h;
    }
};

// 3 0 6 1 5

// 0 1 3 5 6
// 1 <= h <= 5
// h == 5 -> 5개는 5이상 0개는 5 이하의 값 x
// h == 4 -> 4개는 4이상 1개는 1 이하의 값 x
// h == 3 -> 3개는 3이상 2개는 3 이하의 값 o

// h == 5 -> (5 -5)번째 원소는 5이상이여야 함 x
// h == 4 -> (5 - 4)번째 원소는 4이상이여야 함 x
// h == 3 -> (5 - 3)번째 원소는 3이상이야 함 o

// 1 1 3
// 1 <= h <= 3
// h == 3 -> (3 - 3)번째는 3 이상이여야 함 x
// h == 2 -> (3 - 2)번째는 2 이상이여야 함 x
// h == 1 -> (3 - 1)번째는 1 이상이여야 함 