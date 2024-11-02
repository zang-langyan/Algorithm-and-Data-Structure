#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

/* Convex Hull 
 * 
 * Convex Hull Algorithm is to find the intersect set 
 * that surround all points in the set. 
 */

/* 2D Convex Hull
 */
// Data
// 8 |                                       8 |
// 7 |                                       7 |
// 6 |           .                           6 |           x          
// 5 |     .                                 5 |     x             
// 4 |                                 ——>   4 |            
// 3 |        .                              3 |        .
// 2 |                       .               2 |                       x
// 1 |  .                                    1 |  x   
// 0 |        .        .                     0 |        x        x
// --------------------------------          --------------------------------
//      0  1  2  3  4  5  6  7  8                 0  1  2  3  4  5  6  7  8
struct Vec2 {
  int x, y;
  int cross(const Vec2& other){
    return x*other.y - y*other.x;
  };
  Vec2 operator-(const Vec2& other){
    return Vec2{x-other.x, y-other.y};
  };
  friend std::ostream& operator<<(std::ostream& os, Vec2& v){
    os << "(";
    os << v.x << "," << v.y;
    os << ")";
    os << std::endl;
    return os;
  };
};

using Point = Vec2;

static int n = 7;
static std::vector<Point> g_points{
    {0,1},
    {2,3},
    {3,6},
    {1,5},
    {2,0},
    {7,2},
    {5,0},
};

std::function<bool(Point, Point)> comparePoint = [](Point a, Point b){
  return a.x == b.x ? a.y <= b.y : a.x < b.x;
};

/*
 * 1. Andrew's Algorithm
 */
std::vector<Point> andrew_ConvexHull(std::vector<Point> points){
  int n = points.size();
  if (n <= 3) return points;
  std::sort(points.begin(), points.end(), comparePoint);
  std::vector<Point> ans(2*n);
  int k = 0;
  for (int i = 0; i < n; ++i){
    while (k >= 2 && (ans[k-1]-ans[k-2]).cross(points[i]-ans[k-2]) <= 0) {
      --k;
    }
    ans[k++] = points[i];
  }
  for (int i = n-1, t = k+1; i > 0; --i){
    while (k >= t && (ans[k-1]-ans[k-2]).cross(points[i-1]-ans[k-2]) <= 0) {
      --k;
    }
    ans[k++] = points[i-1];
  }
  ans.resize(k-1);
  return ans;
}


int main() {
  auto convex_hull = andrew_ConvexHull(g_points);
  for (auto p : convex_hull){
    std::cout << p;
  }
}

