#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3

class Solution {
public:
    bool isSelfCrossing(vector<int> &distances) {
        if (distances.size() < 3) {
            return false;
        }

        vector<pair<int, int>> points;

        int curX, curY;
        curX = curY = 0;
        points.push_back({0, 0});

        for (int i = 0; i < distances.size(); i++) {
            int &distance = distances.at(i);
            switch (i % 4) {
                case NORTH:
                    curY += distance;
                    break;
                case WEST:
                    curX -= distance;
                    break;
                case SOUTH:
                    curY -= distance;
                    break;
                default:
                    curX += distance;
                    break;
            }
            points.push_back({curX, curY});
        }

        for (int i = 0; i < points.size(); i++) {
            if (i + 4 < points.size() && isCross(points.at(i), points.at(i + 1), points.at(i + 3), points.at(i + 4))) {
                return true;
            }
            if (i + 5 < points.size() && isCross(points.at(i), points.at(i + 5))) {
                return true;
            }
            if (i + 6 < points.size() && isCross(points.at(i), points.at(i + 1), points.at(i + 5), points.at(i + 6))) {
                return true;
            }
        }

        return false;
    }

    bool isCross(pair<int, int> point1, pair<int, int> point2){
        return point1.first == point2.first && point1.second == point2.second;
    }

    bool isCross(pair<int, int> line1Src, pair<int, int> line1Dest, pair<int, int> line2Src, pair<int, int> line2Dest) {
        if (line1Src.first != line1Dest.first) {
            swap(line1Src, line2Src);
            swap(line1Dest, line2Dest);
        }
        return min(line2Src.first, line2Dest.first) <= line1Src.first
               && line1Src.first <= max(line2Src.first, line2Dest.first)
               && min(line1Src.second, line1Dest.second) <= line2Src.second
               && line2Src.second <= max(line1Src.second, line1Dest.second);
    };
};