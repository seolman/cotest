#include <functional>
#include <iostream>
#include <queue>
#include <string>
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

int solution(int n, vector<vector<int>> costs) {
  vector<vector<pair<int, int>>> graph(n);
  for (const auto &c : costs) {
    int from = c[0];
    int to = c[1];
    int w = c[2];
    graph[from].push_back({w, to});
    graph[to].push_back({w, from});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<bool> visited(n, false);
  visited[0] = true;
  for (const auto &edge : graph[0]) {
    pq.push(edge);
  }

  int answer = 0;
  int connected_count = 1;

  while (!pq.empty() && connected_count < n) {
    int cost = pq.top().first;
    int next_node = pq.top().second;
    pq.pop();

    if (visited[next_node]) {
      continue;
    }

    visited[next_node] = true;
    answer += cost;
    connected_count++;

    for (const auto &edge : graph[next_node]) {
      if (!visited[edge.second]) {
        pq.push(edge);
      }
    }
  }

  return answer;
}

int main() {
  int n = 4;
  vector<vector<int>> costs = {
      {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
  int expected = 4;
  int result = solution(n, costs);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
