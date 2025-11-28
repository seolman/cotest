#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

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