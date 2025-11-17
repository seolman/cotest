#include <vector>

using namespace std;

int dfs(const vector<int> &numbers, int target, int idx, int sum) {
  if (idx == numbers.size()) {
    if (target == sum) {
      return 1;
    } else {
      return 0;
    }
  }

  int add_path = dfs(numbers, target, idx + 1, sum + numbers[idx]);
  int sub_path = dfs(numbers, target, idx + 1, sum - numbers[idx]);
  return add_path + sub_path;
}

int solution(vector<int> numbers, int target) {
  int answer = dfs(numbers, target, 0, 0);
  return answer;
}
