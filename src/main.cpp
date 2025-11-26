#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    os << *it;
    if (it != vec.end() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

int solution(vector<vector<int>> triangle) {
  for (int i = 1; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      if (j == 0) {
        triangle[i][j] += triangle[i - 1][j];
      } else if (j == triangle[i].size() - 1) {
        triangle[i][j] += triangle[i - 1][j - 1];
      } else {
        triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
      }
    }
  }
  int answer = *max_element(triangle.back().begin(), triangle.back().end());
  return answer;
}

int main() {
  cout << "TESTING" << endl;

  vector<vector<int>> triangle = {
      {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
  int expected = 30;
  int result = solution(triangle);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
