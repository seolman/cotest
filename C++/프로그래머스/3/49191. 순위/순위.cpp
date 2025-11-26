#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
  int answer = 0;
  vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

  for (const auto &result : results) {
    int a = result[0];
    int b = result[1];
    graph[a][b] = true;
  }

  for (int k = 1; k < n + 1; k++) {
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (graph[i][k] && graph[k][j]) {
          graph[i][j] = true;
        }
      }
    }
  }

  for (int i = 1; i < n + 1; i++) {
    int count = 0;
    for (int j = 1; j < n + 1; j++) {
      if (graph[i][j] || graph[j][i]) {
        count++;
      }
    }
    if (count == n - 1) {
      answer++;
    }
  }

  return answer;
}