#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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
