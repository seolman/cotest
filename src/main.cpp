#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    os << *it;
    if (it != vec.end() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

int solution(int n, vector<vector<int>> edge) {
  int answer = 0;
  vector<vector<int>> adj(n + 1);
  vector<int> distance(n + 1, -1);

  for (const auto &e : edge) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  queue<int> q;
  distance[1] = 0;
  q.push(1);

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (const int &next : adj[current]) {
      if (distance[next] == -1) {
        q.push(next);
        distance[next] = distance[current] + 1;
      }
    }
  }

  int max = *max_element(distance.begin() + 1, distance.end());
  for (const auto &d : distance) {
    if (max == d) {
      answer++;
    }
  }
  return answer;
}

int main() {
  cout << "TESTING" << endl;

  int n = 6;
  vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3},
                              {1, 2}, {2, 4}, {5, 2}};
  int expected = 3;
  int result = solution(n, edge);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
