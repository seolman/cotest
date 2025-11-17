#include <cwchar>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
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

bool can_change(const string &begin, const string &target) {
  int diff_count = 0;
  for (int i = 0; i < begin.length(); i++) {
    if (begin[i] != target[i]) {
      diff_count++;
    }
  }
  return diff_count == 1;
}

int solution(string begin, string target, vector<string> words) {
  bool target_exist = false;
  for (const auto &w : words) {
    if (w == target) {
      target_exist = true;
      break;;
    }
  }
  if (!target_exist) {
    return 0;
  }

  queue<pair<string, int>> q;
  unordered_set<string> visited;

  q.push({begin, 0});
  visited.insert(begin);

  while (!q.empty()) {
    string current_string = q.front().first;
    int current_step = q.front().second;
    q.pop();

    if (current_string == target) {
      return current_step;
    }

    for (const string &w : words) {
      if (visited.find(w) == visited.end() && can_change(current_string, w)) {
        visited.insert(w);
        q.push({w, current_step + 1});
      }
    }
  }

  return 0;
}

int main() {
  string begin = "hit";
  string target = "cog";
  vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
  int expected = 4;
  int result = solution(begin, target, words);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
