#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
  int answer = 0;
  int dy[] = {-1, 0, 0, 1};
  int dx[] = {0, 1, -1, 0};
  for (int i = 0; i < 4; i++) {
    int next_y = h + dy[i];
    int next_x = w + dx[i];

    if (next_y < 0 || next_y > board.size() - 1 || next_x < 0 ||
        next_x > board[0].size() - 1) {
      continue;
    }

    if (board[next_y][next_x] == board[h][w]) {
      answer++;
    }
  }
  return answer;
}
