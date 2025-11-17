#include <iostream>
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

int main() {
  vector<int> numbers = {1, 1, 1, 1, 1};
  int target = 3;
  int expected = 5;
  int result = solution(numbers, target);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  numbers = {4, 1, 2, 1};
  target = 4;
  expected = 2;
  result = solution(numbers, target);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
