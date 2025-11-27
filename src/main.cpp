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

int rob(vector<int> &money) {
  int prev1 = 0;
  int prev2 = 0;
  for (const int &m : money) {
    int current_max = max(prev1, m + prev2);
    prev2 = prev1;
    prev1 = current_max;
  }

  return prev1;
}

int solution(vector<int> money) {
  vector<int> case1(money.begin(), money.end() - 1);
  int max1 = rob(case1);
  vector<int> case2(money.begin() + 1, money.end());
  int max2 = rob(case2);
  return max(max1, max2);
}

int main() {
  cout << "TESTING" << endl;

  vector<int> money = {1, 2, 3, 1};
  int expected = 4;
  int result = solution(money);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
