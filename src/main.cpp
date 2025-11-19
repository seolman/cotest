#include <algorithm>
#include <functional>
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

struct cmp {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  }
};

int solution(vector<vector<int>> jobs) {
  int answer = 0;
  sort(jobs.begin(), jobs.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  int idx = 0;
  int time = 0;
  while (idx < jobs.size() || !pq.empty()) {
    if (idx < jobs.size() && jobs[idx][0] <= time) {
      pq.push({jobs[idx][0], jobs[idx][1]});
      idx++;
      continue;
    }

    if (!pq.empty()) {
      time += pq.top().second;
      answer += time - pq.top().first;
      pq.pop();
    } else {
      time = jobs[idx][0];
    }
  }

  return answer / jobs.size();
}

int main() {
  vector<vector<int>> jobs = {{0, 3}, {1, 9}, {3, 5}};
  int expected = 8;
  int result = solution(jobs);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
