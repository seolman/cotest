#include <string>
#include <vector>

using namespace std;

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