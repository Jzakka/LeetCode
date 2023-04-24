
class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0;
        int r = height.size() - 1;
        int max = 0;

        while (l < r) {
            if(height.at(l) > height.at(r)){
                max = std::max(max, (r - l) * height.at(r));
                r--;
            }
            else {
                max = std::max(max, (r - l) * height.at(l));
                l++;
            }
        }

        return max;
    }
};
