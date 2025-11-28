#include <iostream>
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

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    os << *it;
    if (it != vec.end() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

int main() {
  cout << "TESTING" << endl;

  vector<vector<string>> board = {{"blue", "red", "orange", "red"},
                                  {"red", "red", "blue", "orange"},
                                  {"blue", "orange", "red", "red"},
                                  {"orange", "orange", "red", "blue"}};
  int h = 1;
  int w = 1;
  int expected = 2;
  int result = solution(board, h, w);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
