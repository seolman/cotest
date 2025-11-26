#include <iostream>
#include <map>
#include <unordered_set>
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

int solution(int N, int number) {
  if (N == number) {
    return 1;
  }

  vector<unordered_set<int>> dp(9);

  int concat_n = 0;
  for (int i = 1; i < 9; i++) {
    concat_n = concat_n * 10 + N;
    dp[i].insert(concat_n);
  }

  for (int k = 2; k < 9; k++) {
    for (int i = 1; i < k; i++) {
      int j = k - i;

      for (const int num1 : dp[i]) {
        for (const int num2 : dp[j]) {
          dp[k].insert(num1 + num2);
          dp[k].insert(num1 - num2);
          dp[k].insert(num1 * num2);
          if (num2 != 0) {
            dp[k].insert(num1 / num2);
          }
        }
      }
    }

    if (dp[k].count(number)) {
      return k;
    }
  }

  return -1;
}

int main() {
  cout << "TESTING" << endl;

  int n = 5;
  int number = 12;
  int expected = 4;
  int result = solution(n, number);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
