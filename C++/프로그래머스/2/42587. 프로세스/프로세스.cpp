#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;


int solution(vector<int> priorities, int location) {
  int answer = 0;
  queue<pair<int, int>> q;
  priority_queue<int> pq;
  for (int i = 0; i < priorities.size(); i++) {
    q.push({priorities[i], i});
    pq.push(priorities[i]);
  }

  while (!q.empty()) {
    int current_priority = q.front().first;
    int current_location = q.front().second;
    q.pop();

    if (current_priority < pq.top()) {
      q.push({current_priority, current_location});
    } else {
      answer++;
      pq.pop();

      if (current_location == location) {
        return answer;
      }
    }
  }

  return answer;
}
