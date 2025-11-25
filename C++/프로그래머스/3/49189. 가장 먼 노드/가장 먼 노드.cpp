#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

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