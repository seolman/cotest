#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  }
};

int solution(vector<vector<int>> jobs) {
  int answer = 0;
  sort(jobs.begin(), jobs.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  int idx = 0;
  int time = 0;
  while (idx < jobs.size() || !pq.empty()) {
    if (idx < jobs.size() && jobs[idx][0] <= time) {
      pq.push({jobs[idx][0], jobs[idx][1]});
      idx++;
      continue;
    }

    if (!pq.empty()) {
      time += pq.top().second;
      answer += time - pq.top().first;
      pq.pop();
    } else {
      time = jobs[idx][0];
    }
  }

  return answer / jobs.size();
}