#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

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