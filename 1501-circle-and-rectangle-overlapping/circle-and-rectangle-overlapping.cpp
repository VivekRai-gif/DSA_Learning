class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        auto clamp = [](int val, int lo, int hi) {
            return std::max(lo, std::min(val, hi));
        };

        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);

        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;
        long long r = radius;

        return dx * dx + dy * dy <= r * r;
    }
};