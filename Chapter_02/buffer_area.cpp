// A buffer region is an area created around a geographic feature at a specified distance.
// For example, a 1 km buffer around a water point represents all areas located within 1 km of that water source.
// Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

// Write a program that creates buffers of different sizes around a specific point coordinate and returns the points in a given set that lie within each buffer.
import std;

using namespace std;

struct Point {
    double x;
    double y;
};

double distance(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

map<double, vector<Point>> pointsInBuffers(
    const Point& center,
    const vector<Point>& points,
    const vector<double>& radii
) {
    map<double, vector<Point>> result;
    for (double r : radii) {
        result[r] = {};
    }

    for (const auto& p : points) {
        double d = distance(center, p);
        for (double r : radii) {
            if (d <= r) {
                result[r].push_back(p);
            }
        }
    }

    return result;
}

int main() {
    Point center{0.0, 0.0};

    vector<Point> candidates = {
        {0.5, 0.5},   // dist ~= 0.707
        {1.0, 0.0},   // dist = 1.0
        {2.0, 0.0},   // dist = 2.0
        {0.0, 3.0},   // dist = 3.0
        {-1.5, 1.5},  // dist ~= 2.121
    };

    vector<double> buffers = {1.0, 2.0, 2.5};

    auto inside = pointsInBuffers(center, candidates, buffers);

    for (const auto& [r, pts] : inside) {
        cout << format("Buffer r = {}: ", r);
        cout << "[";
        for (size_t i = 0; i < pts.size(); ++i) {
            cout << format("({}, {})", pts[i].x, pts[i].y);
            if (i + 1 < pts.size()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}