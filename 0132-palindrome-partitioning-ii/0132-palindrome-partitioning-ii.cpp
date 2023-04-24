class Solution { ;
public:
    int minCut(string s) {
        int n = s.length();
        // 이거 멤버변수로 하면 시간초과남
        // 메모리 스택의 탑은 항상 L1 캐시에 있고
        // 객체가 스택에 푸시되려면 L2 캐시에 로드되기 때문에
        // 둘의 속도 차이는 10~100배 차이가 날 수도 있음
        vector<int> DP(n + 1, -1);
        return recursive(s, 0, n - 1, DP);
    }

    int recursive(const string &s, int start, int end, vector<int> &DP) {
        if (isPalindrome(s, start, end)) {
            return 0;
        }
        if (DP[start] != -1) {
            return DP[start];
        }
        int minVal = INT32_MAX;
        for (int cut = start; cut < end; cut++) {
            if (isPalindrome(s, start, cut)) {
                int right = recursive(s, cut + 1, end, DP);
                minVal = min(minVal, right + 1);
            }
        }

        DP[start] = minVal;
        return minVal;
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};