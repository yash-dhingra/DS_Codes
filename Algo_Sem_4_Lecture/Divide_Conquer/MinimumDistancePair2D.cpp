#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat> // For DBL_MAX

using namespace std;

// Structure to represent a point in 2D plane
struct Point
{
    int x, y;
};

// Function to calculate the distance between two points
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to compare points based on their x-coordinate
bool compareX(Point p1, Point p2)
{
    return p1.x < p2.x;
}

// Function to compare points based on their y-coordinate
bool compareY(Point p1, Point p2)
{
    return p1.y < p2.y;
}

// Function to find the closest pair of points recursively
double closestPairUtil(vector<Point> &points, int l, int r)
{
    if (r - l <= 3)
    {
        // If there are few points, use brute force
        double minDistance = DBL_MAX;
        for (int i = l; i < r; ++i)
        {
            for (int j = i + 1; j < r; ++j)
            {
                minDistance = min(minDistance, dist(points[i], points[j]));
            }
        }
        return minDistance;
    }

    // Find the middle point
    int mid = (l + r) / 2;
    Point midPoint = points[mid];

    // Recursively find the minimum distance in left and right subarrays
    double dLeft = closestPairUtil(points, l, mid);
    double dRight = closestPairUtil(points, mid + 1, r);

    // Find the minimum of two distances
    double minDistance = min(dLeft, dRight);

    // Find points that are within the minimum distance around the middle line
    vector<Point> strip;
    for (int i = l; i < r; ++i)
    {
        if (abs(points[i].x - midPoint.x) < minDistance)
        {
            strip.push_back(points[i]);
        }
    }

    // Sort the strip based on y-coordinate
    sort(strip.begin(), strip.end(), compareY);

    // Compare points in the strip to find smaller distances
    for (size_t i = 0; i < strip.size(); ++i)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDistance; ++j)
        {
            minDistance = min(minDistance, dist(strip[i], strip[j]));
        }
    }

    return minDistance;
}

// Function to find the closest pair of points
double closestPair(vector<Point> &points)
{
    // Sort the points based on x-coordinate
    sort(points.begin(), points.end(), compareX);

    // Call the recursive helper function
    return closestPairUtil(points, 0, points.size());
}

int main()
{
    // Example points
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    // Find the closest pair
    double closest = closestPair(points);

    // Output the closest pair
    cout << "Closest distance: " << closest << endl;

    return 0;
}
