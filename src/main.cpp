#include <iostream>
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

void dfs(int n, vector<vector<int>> &computers, int idx,
         vector<bool> &visited) {
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

int main() {
  int n = 3;
  vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  int expected = 2;
  int result = solution(n, computers);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  n = 3;
  computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
  expected = 1;
  result = solution(n, computers);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
