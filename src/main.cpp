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

int solution(int m, int n, vector<vector<int>> puddles) {
  int mod = 1000000007;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (const auto &puddle : puddles) {
    dp[puddle[1]][puddle[0]] = -1;
  }

  dp[1][1] = 1;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (dp[i][j] == -1) {
        dp[i][j] = 0;
        continue;
      }

      if (i > 1) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
      }
      if (j > 1) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      }
    }
  }
  return dp[n][m];
}

int main() {
  cout << "TESTING" << endl;

  int m = 4;
  int n = 3;
  vector<vector<int>> puddles = {{2, 2}};
  int expected = 4;
  int result = solution(m, n, puddles);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
