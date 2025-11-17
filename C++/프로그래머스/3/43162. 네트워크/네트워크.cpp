#include <string>
#include <vector>

using namespace std;
void dfs(int n, vector<vector<int>> computers, int idx, vector<bool> &visited) {
  visited[idx] = true;
  for (int i = 0; i < n; i++) {
    if (computers[idx][i] == 1 && !visited[i]) {
      dfs(n, computers, i, visited);
    }
  }
}

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      answer++;
      dfs(n, computers, i, visited);
    }
  }
  return answer;
}
