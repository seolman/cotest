#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  sort(rocks.begin(), rocks.end());
  int low = 1;
  int high = distance;
  int answer = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int removed = 0;
    int pos = 0;

    for (const auto &rock : rocks) {
      if (rock - pos < mid) {
        removed++;
      } else {
        pos = rock;
      }
    }

    if (distance - pos < mid) {
      removed++;
    }

    if (removed <= n) {
      answer = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return answer;
}

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

int main() {
  cout << "TESTING" << endl;

  int distance = 25;
  vector<int> rocks = {2, 14, 11, 21, 17};
  int n = 2;
  int expected = 4;
  int result = solution(distance, rocks, n);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
