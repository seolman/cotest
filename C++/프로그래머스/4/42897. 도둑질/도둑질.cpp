#include <string>
#include <vector>
#include <numeric>


using namespace std;

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

