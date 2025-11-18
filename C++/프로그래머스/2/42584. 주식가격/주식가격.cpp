#include <string>
#include <vector>
#include <stack>

using namespace std;

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
