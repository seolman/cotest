#include <iostream>
#include <queue>
#include <utility>
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

int solution(vector<int> priorities, int location) {
  int answer = 0;
  queue<pair<int, int>> q;
  priority_queue<int> pq;
  for (int i = 0; i < priorities.size(); i++) {
    q.push({priorities[i], i});
    pq.push(priorities[i]);
  }

  while (!q.empty()) {
    int current_priority = q.front().first;
    int current_location = q.front().second;
    q.pop();

    if (current_priority < pq.top()) {
      q.push({current_priority, current_location});
    } else {
      answer++;
      pq.pop();

      if (current_location == location) {
        return answer;
      }
    }
  }

  return answer;
}

int main() {
  vector<int> priorities = {2, 1, 3, 2};
  auto location = 2;
  auto expected = 1;
  auto result = solution(priorities, location);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  priorities = {1, 1, 9, 1, 1, 1};
  location = 0;
  expected = 5;
  result = solution(priorities, location);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
