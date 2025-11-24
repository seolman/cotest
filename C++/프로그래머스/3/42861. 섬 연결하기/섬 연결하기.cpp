#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


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
