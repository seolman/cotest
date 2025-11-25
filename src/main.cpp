#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
  sort(times.begin(), times.end());
  long long low = 1;
  long long high = (long long)n * times.back();
  long long answer = high;

  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long processed = 0;

    for (const auto &time : times) {
      processed += mid / time;

      if (processed >= n) {
        break;
      }
    }

    if (processed >= n) {
      answer = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
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

  int n = 6;
  vector<int> times = {7, 10};
  int expected = 28;
  int result = solution(n, times);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
