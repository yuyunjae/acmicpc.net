#include <cmath>
#include <iostream>

using namespace std;

typedef struct s_point {
  long long x;
  long long y;
} t_point;

typedef struct s_line {
  t_point point1;
  t_point point2;
} t_line;

t_point to_vector(t_point& point1, t_point& point2) {
  return {point1.x - point2.x, point1.y - point2.y};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  t_line line1;
  t_line line2;

  cin >> line1.point1.x >> line1.point1.y >> line1.point2.x >> line1.point2.y;
  cin >> line2.point1.x >> line2.point1.y >> line2.point2.x >> line2.point2.y;

  t_point vec, p1, p2;
  vec = to_vector(line1.point1, line1.point2);
  p1 = to_vector(line1.point1, line2.point1);
  p2 = to_vector(line1.point1, line2.point2);

  int temp1 = (vec.x * p2.y - p2.x * vec.y) < 0 ? -1 : 1;
  int temp2 = (vec.x * p1.y - p1.x * vec.y) < 0 ? -1 : 1;

  if (temp1 * temp2 >= 0) {
    cout << 0;
    return 0;
  }

  vec = to_vector(line2.point1, line2.point2);
  p1 = to_vector(line2.point1, line1.point1);
  p2 = to_vector(line2.point1, line1.point2);

  temp1 = (vec.x * p2.y - p2.x * vec.y) < 0 ? -1 : 1;
  temp2 = (vec.x * p1.y - p1.x * vec.y) < 0 ? -1 : 1;

  if (temp1 * temp2 >= 0)
    cout << 0;
  else
    cout << 1;
  return 0;
}

// #include <cmath>
// #include <iostream>

// using namespace std;

// typedef struct s_point {
//   long long x;
//   long long y;
// } t_point;

// typedef struct s_line {
//   t_point point1;
//   t_point point2;
// } t_line;

// int ccw(t_point point1, t_point point2, t_point point3) {
//   long long result = (point2.x - point1.x) * (point3.y - point1.y) -
//                      (point2.y - point1.y) * (point3.x - point1.x);
//   return result > 0 ? 1 : -1;
// }

// int main(void) {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);

//   t_line line1;
//   t_line line2;

//   cin >> line1.point1.x >> line1.point1.y >> line1.point2.x >>
//   line1.point2.y; cin >> line2.point1.x >> line2.point1.y >> line2.point2.x
//   >> line2.point2.y;

//   if (ccw(line1.point1, line1.point2, line2.point1) *
//               ccw(line1.point1, line1.point2, line2.point2) <
//           0 &&
//       ccw(line2.point1, line2.point2, line1.point1) *
//               ccw(line2.point1, line2.point2, line1.point2) <
//           0)
//     cout << 1;
//   else
//     cout << 0;
//   return 0;
// }