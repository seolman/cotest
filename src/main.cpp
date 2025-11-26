#include <algorithm>
#include <iostream>
#include <queue>
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

int main() {
  cout << "TESTING" << endl;

  int n = 5;
  vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
  int expected = 2;
  int result = solution(n, results);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
