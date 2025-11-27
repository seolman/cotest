#include <vector>
#include <string>
#include <climits>

using namespace std;

int solution(vector<string> arr) {
  vector<int> nums;
  vector<char> ops;
  for (int i = 0; i < arr.size(); i++) {
    if (i % 2 == 0) {
      nums.push_back(stoi(arr[i]));
    } else {
      ops.push_back(arr[i][0]);
    }
  }

  const int n = nums.size();
  vector<vector<int>> max_dp(n, vector<int>(n, INT_MIN));
  vector<vector<int>> min_dp(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    max_dp[i][i] = nums[i];
    min_dp[i][i] = nums[i];
  }

  for (int len = 2; len < n + 1; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        if (ops[k] == '+') {
          max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k + 1][j]);
          min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k + 1][j]);
        } else {
          max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k + 1][j]);
          min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k + 1][j]);
        }
      }
    }
  }
  return max_dp[0][n - 1];
}