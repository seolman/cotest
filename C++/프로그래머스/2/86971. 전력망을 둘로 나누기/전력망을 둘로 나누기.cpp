#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int bfs(const vector<vector<int>> &graph, int start, int ignore1, int ignore2,
        int n) {
  int count = 1;
  queue<int> q;
  vector<int> visited(n + 1, false);

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current_node = q.front();
    q.pop();

    for (int n : graph[current_node]) {
      if ((current_node == ignore1 && n == ignore2) ||
          (current_node == ignore2 && n == ignore1)) {
        continue;
      }

      if (!visited[n]) {
        count++;
        visited[n] = true;
        q.push(n);
      }
    }
  }
  return count;
}

int solution(int n, vector<vector<int>> wires) {
  int answer = INT_MAX;
  vector<vector<int>> graph(n + 1);
  for (const auto &w : wires) {
    graph[w[0]].push_back(w[1]);
    graph[w[1]].push_back(w[0]);
  }

  for (const auto &w : wires) {
    int v1 = w[0];
    int v2 = w[1];

    int count1 = bfs(graph, v1, v1, v2, n);
    int count2 = n - count1;
    answer = min(answer, abs(count1 - count2));
  }
  return answer;
}