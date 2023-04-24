class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        queue<pair<int, char>> indiciesQueue;
        // t의 문자들을 집합에 넣기
        for (auto &let: t) {
            map[let]++;
        }
        int start, end, minStart, minEnd;
        start = end = 0;
        int minLen = INT32_MAX;
        while (end < s.length()) {
            while (end < s.length() && !include(map)) {
                if (map.find(s.at(end)) != map.end()) {
                    map[s.at(end)]--;
                    indiciesQueue.push({end, s.at(end)});
                }
                end++;
            }
            pair<int, char> front = {-1, '0'};
            while (include(map)) {
                front = indiciesQueue.front();
                map[s.at(front.first)]++;
                indiciesQueue.pop();
                start++;
            }
            if (front.first != -1 && minLen > end - front.first) {
                minStart = front.first;
                minEnd = end;
                minLen = minEnd - minStart;
            }
        }

        return minLen == INT32_MAX ? "" : s.substr(minStart, minLen);
    }

    bool include(unordered_map<char, int> &map) {
        for (auto &e: map) {
            if (e.second > 0) return false;
        }
        return true;
    }
};