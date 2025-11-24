#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{ ";
  for (size_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i != vec.size() - 1) {
      os << ", ";
    }
  }
  os << " }";
  return os;
}

bool cmp(const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
  sort(routes.begin(), routes.end(), cmp);
  int answer = 1;
  int cam_pos = routes[0][1];

  for (int i = 1; i < routes.size(); i++) {
    if (routes[i][0] > cam_pos) {
      answer++;
      cam_pos = routes[i][1];
    }
  }

  return answer;
}

int main() {
  vector<vector<int>> routes = {{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}};
  int expected = 2;
  int result = solution(routes);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
