class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest x-coordinate on the rectangle
        int closestX = max(x1, min(xCenter, x2));

        // Find the closest y-coordinate on the rectangle
        int closestY = max(y1, min(yCenter, y2));

        // Distance from circle center to closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Compare squared distances
        return dx * dx + dy * dy <= radius * radius;
    }
};