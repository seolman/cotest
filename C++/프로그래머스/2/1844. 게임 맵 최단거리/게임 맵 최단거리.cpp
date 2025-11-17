#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<tuple<int, int, int>> q;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  q.push({0, 0, 1});
  visited[0][0] = true;

  while (!q.empty()) {
    auto [r, c, dist] = q.front();
    q.pop();

    if (r == n - 1 && c == m - 1) {
      return dist;
    }

    for (int i = 0; i < 4; i++) {
      int next_r = r + dr[i];
      int next_c = c + dc[i];

      if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m &&
          maps[next_r][next_c] == 1 && !visited[next_r][next_c]) {
        visited[next_r][next_c] = true;
        q.push({next_r, next_c, dist + 1});
      }
    }
  }

  return -1;
}
