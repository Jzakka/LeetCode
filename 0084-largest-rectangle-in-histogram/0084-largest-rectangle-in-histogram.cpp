
class Solution {
private:
    void calc(const vector<int> &heights, vector<int>& maxLimits, stack<pair<int,int>>& stk, int i, int sz) {
        if (stk.empty()) {
            stk.push({heights[i], i});
            maxLimits[i] = sz;
        } else {
            while (!stk.empty() && stk.top().first >= heights[i]) {
                stk.pop();
            }
            maxLimits[i] = stk.empty() ? sz : stk.top().second;
            stk.push({heights[i], i});
        }
    }

public:
    int largestRectangleArea(vector<int> &heights) {
        int sz = heights.size();
        vector<int> maxRights(sz, 0);
        vector<int> maxLefts(sz, 0);
        stack<pair<int, int>> smallestReverse;
        stack<pair<int, int>> smallest;

        for (int i = sz - 1; i >= 0; i--) {
            //calc maxRight;
            calc(heights,maxRights,smallestReverse, i, sz);
            //calc maxLeft;
            calc(heights, maxLefts,smallest, sz - i - 1, -1);
        }

        int maxArea = INT32_MIN;
        for (int i = 0; i < sz; i++) {
            maxArea = max(maxArea, (maxRights[i] - maxLefts[i] - 1) * heights[i]);
        }

        return maxArea;
    }
};