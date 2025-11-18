#include <iostream>
#include <stack>
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

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size());
  stack<int> s;
  for (int i = 0; i < prices.size(); i++) {
    while (!s.empty() && prices[s.top()] > prices[i]) {
      int top_idx = s.top();
      s.pop();

      answer[top_idx] = i - top_idx;
    }
    s.push(i);
  }

  while (!s.empty()) {
    int top_idx = s.top();
    s.pop();

    answer[top_idx] = (prices.size() - 1) - top_idx;
  }
  return answer;
}

int main() {
  vector<int> prices = {1, 2, 3, 2, 3};
  vector<int> expected = {4, 3, 1, 1, 0};
  vector<int> result = solution(prices);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
