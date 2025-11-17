#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY,
             int itemX, int itemY) {
  vector<vector<int>> board(102, vector<int>(102, 0));
  for (const auto &rect : rectangle) {
    int x1 = rect[0] * 2;
    int y1 = rect[1] * 2;
    int x2 = rect[2] * 2;
    int y2 = rect[3] * 2;
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (board[i][j] == 1) {
          continue;
        }
        if (i == y1 || i == y2 || j == x1 || j == x2) {
          board[i][j] = 2;
        } else {
          board[i][j] = 1;
        }
      }
    }
  }

  queue<pair<int, int>> q;
  vector<vector<int>> dist(102, vector<int>(102, 1));
  q.push({characterY * 2, characterX * 2});

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (r == itemY * 2 && c == itemX * 2) {
      return dist[r][c] / 2;
    }

    for (int i = 0; i < 4; i++) {
      int next_r = r + dr[i];
      int next_c = c + dc[i];

      if (next_r >= 0 && next_r < 102 && next_c >= 0 && next_c < 102 &&
          dist[next_r][next_c] == 1 && board[next_r][next_c] == 2) {
        dist[next_r][next_c] += dist[r][c];
        q.push({next_r, next_c});
      }
    }
  }

  return -1;
}