class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = (ax2 - ax1) * (ay2 - ay1);
        int bArea = (bx2 - bx1) * (by2 - by1);

        int xOverLap = min(ax2, bx2) - max(ax1, bx1);
        int yOverLap = min(ay2, by2) - max(ay1, by1);
        int overLapArea = xOverLap > 0 && yOverLap > 0 ? xOverLap * yOverLap : 0;

        return aArea + bArea - overLapArea;
    }
};