#include <algorithm>
#include <iostream>
#include <unordered_map>
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

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext,
                             string sort_by) {
  vector<vector<int>> answer;

  unordered_map<string, int> m;
  m.insert({"code", 0});
  m.insert({"date", 1});
  m.insert({"maximum", 2});
  m.insert({"remain", 3});

  for (const auto &d : data) {
    int idx = m[ext];
    if (d[idx] < val_ext) {
      answer.push_back(d);
    }
  }

  int idx = m[sort_by];
  sort(answer.begin(), answer.end(),
       [&](const vector<int> &a, const vector<int> &b) {
         return a[idx] < b[idx];
       });

  return answer;
}

int main() {
  cout << "TESTING" << endl;

  vector<vector<int>> data = {
      {1, 20300104, 100, 80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8}};
  string ext = "date";
  int val_ext = 20300501;
  string sort_by = "remain";
  vector<vector<int>> expected = {{3, 20300401, 10, 8}, {1, 20300104, 100, 80}};
  vector<vector<int>> result = solution(data, ext, val_ext, sort_by);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
