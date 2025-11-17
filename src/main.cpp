#include <algorithm>
#include <iostream>
#include <queue>
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

void extract(int r, int c, int target, vector<vector<int>> &board,
             vector<bool> &visited, vector<pair<int, int>> &shape) {
  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r * board.size() + c] = true;
  shape.push_back({r, c});

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [cur_r, cur_c] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_r = cur_r + dr[i];
      int next_c = cur_c + dc[i];

      if (next_r < 0 || next_r >= board.size() || next_c < 0 ||
          next_c >= board.size() || board[next_r][next_c] != target ||
          visited[next_r * board.size() + next_c]) {
        continue;
      }

      visited[next_r * board.size() + next_c] = true;
      q.push({next_r, next_c});
      shape.push_back({next_r, next_c});
    }
  }
}

void normalize(vector<pair<int, int>> &shape, int n) {
  int min_r = n;
  int min_c = n;
  for (auto &pair : shape) {
    min_r = min(pair.first, min_r);
    min_c = min(pair.second, min_c);
  }

  for (auto &pair : shape) {
    pair.first -= min_r;
    pair.second -= min_c;
  }

  sort(shape.begin(), shape.end());
}

vector<pair<int, int>> rotate(const vector<pair<int, int>> &shape, int n) {
  vector<pair<int, int>> rotated_shape;
  int max_r = 0;
  for (const auto &p : shape) {
    max_r = max(max_r, p.first);
  }
  for (const auto &p : shape) {
    rotated_shape.push_back({p.second, max_r - p.first});
  }
  normalize(rotated_shape, n);
  return rotated_shape;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
  int n = game_board.size();
  vector<bool> board_visited(n * n, false);
  vector<bool> table_visited(n * n, false);
  vector<vector<pair<int, int>>> holes;
  vector<vector<pair<int, int>>> pieces;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (game_board[i][j] == 0 && !board_visited[i * n + j]) {
        vector<pair<int, int>> hole;
        extract(i, j, 0, game_board, board_visited, hole);
        normalize(hole, game_board.size());
        holes.push_back(hole);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pair<int, int> piece;
      if (table[i][j] == 1 && !table_visited[i * n + j]) {
        vector<pair<int, int>> piece;
        extract(i, j, 1, table, table_visited, piece);
        normalize(piece, table.size());
        pieces.push_back(piece);
      }
    }
  }

  int answer = 0;
  vector<bool> piece_used(pieces.size(), false);
  for (int i = 0; i < holes.size(); i++) {
    bool hole_filled = false;
    for (int j = 0; j < pieces.size(); j++) {
      if (piece_used[j])
        continue;
      vector<pair<int, int>> current_piece = pieces[j];
      for (int r = 0; r < 4; r++) {
        if (holes[i] == current_piece) {
          answer += current_piece.size();
          piece_used[j] = true;
          hole_filled = true;
          break;
        }
        current_piece = rotate(current_piece, n);
      }
      if (hole_filled)
        break;
    }
  }

  return answer;
}

int main() {
  vector<vector<int>> game_board = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0},
                                    {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1},
                                    {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
  vector<vector<int>> table = {{1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0},
                               {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0},
                               {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0}};
  int expected = 14;
  int result = solution(game_board, table);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
