#include <algorithm>
#include <iostream>
#include <map>
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

void dfs(string airport, map<string, vector<string>> &graph,
         vector<string> &answer) {
  while (!graph[airport].empty()) {
    string next_airport = graph[airport].back();
    graph[airport].pop_back();
    dfs(next_airport, graph, answer);
  }
  answer.push_back(airport);
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  map<string, vector<string>> graph;
  for (const auto &ticket : tickets) {
    graph[ticket[0]].push_back(ticket[1]);
  }

  for (auto &pair : graph) {
    sort(pair.second.rbegin(), pair.second.rend());
  }

  dfs("ICN", graph, answer);

  reverse(answer.begin(), answer.end());
  return answer;
}

int main() {
  vector<vector<string>> tickets = {
      {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
  vector<string> expected = {"ICN", "JFK", "HND", "IAD"};
  vector<string> result = solution(tickets);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  tickets = {{"ICN", "SFO"},
             {"ICN", "ATL"},
             {"SFO", "ATL"},
             {"ATL", "ICN"},
             {"ATL", "SFO"}};
  expected = {"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"};
  result = solution(tickets);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
