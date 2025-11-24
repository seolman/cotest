#include <algorithm>
#include <iostream>
#include <string>
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

int solution(string name) {
  int answer = 0;
  for (const auto &c : name) {
    answer += min(c - (int)'A', (int)'Z' - c + 1);
  }

  const int n = name.length();
  int min_hor = n - 1;
  for (int i = 0; i < n; i++) {
    int next_idx = i + 1;

    while (next_idx < n && name[next_idx] == 'A') {
      next_idx++;
    }
    int turnaround = i + (n - next_idx) + min(i, n - next_idx);
    min_hor = min(min_hor, turnaround);
  }

  return answer + min_hor;
}

int main() {
  string name = "JEROEN";
  int expected = 56;
  int result = solution(name);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  name = "JAN";
  expected = 23;
  result = solution(name);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
