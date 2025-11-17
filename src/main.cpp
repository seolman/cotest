#include <iostream>
#include <vector>
#include <unordered_map>

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

int solution(vector<int> topping) {
  int answer = 0;
  unordered_map<int, int> left_map;
  unordered_map<int, int> right_map;
  for (int t : topping) {
    right_map[t]++;
  }
  for (int t : topping) {
    left_map[t]++;
    right_map[t]--;
    if (right_map[t] == 0) {
      right_map.erase(t);
    }
    if (left_map.size() == right_map.size()) {
      answer++;
    }
  }
  return answer;
}

int main() {
  vector<int> topping = {1, 2, 1, 3, 1, 4, 1, 2};
  int expected = 2;
  int result = solution(topping);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
