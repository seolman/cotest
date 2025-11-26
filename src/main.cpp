#include <iostream>
#include <map>
#include <vector>

using namespace std;

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

pair<pair<int, int>, pair<int, int>> make_edge(pair<int, int> prev,
                                               pair<int, int> next) {
  if (prev > next) {
    swap(prev, next);
  }
  return {prev, next};
}

int solution(vector<int> arrows) {
  int answer = 0;
  int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
  int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

  map<pair<int, int>, bool> visited_nodes;
  map<pair<pair<int, int>, pair<int, int>>, bool> visited_edges;

  pair<int, int> current_pos = {0, 0};
  visited_nodes[current_pos] = true;

  for (const auto &dir : arrows) {
    for (int i = 0; i < 2; i++) {
      pair<int, int> prev_pos = current_pos;
      current_pos.first += dx[dir];
      current_pos.second += dy[dir];

      if (visited_nodes[current_pos]) {
        if (!visited_edges[make_edge(prev_pos, current_pos)]) {
          answer++;
        }
      }

      visited_nodes[current_pos] = true;
      visited_edges[make_edge(prev_pos, current_pos)] = true;
    }
  }

  return answer;
}

int main() {
  cout << "TESTING" << endl;

  vector<int> arrows = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0,
                        0, 0, 1, 6, 5, 5, 3, 6, 0};
  int expected = 3;
  int result = solution(arrows);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
