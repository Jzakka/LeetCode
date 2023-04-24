class Solution {
public:
    int trap(vector<int>& height) {
        unsigned start=0;

        for (; start < height.size(); ++start) {
            if(height[start] > 0) break;
        }
        if(start >= height.size()) return 0;
        int sum = 0;
        stack<pair<int,int>> stk;
        stk.push({start, height[start]});
        int prevHeight = 0;
        for (unsigned i = start+1; i < height.size(); i++) {
            pair<int, int> next = {i, height.at(i)};
            if (stk.top().second <= next.second) {
                while (!stk.empty() && stk.top().second <= next.second) {
                    sum += (next.first - stk.top().first - 1) * (stk.top().second - prevHeight);
                    prevHeight = stk.top().second;
                    stk.pop();
                }
                if(!stk.empty()) {
                    sum += (next.first- stk.top().first  - 1) * (next.second - prevHeight);
                    prevHeight = next.second;
                }
            } else {
                prevHeight = next.second;
            }
            stk.push(next);
        }
        return sum;
    }
};