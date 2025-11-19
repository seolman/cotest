#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
  priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(),
                                                          scoville.end());
  int answer = 0;
  while (min_heap.size() >= 2 && min_heap.top() < K) {
    answer++;

    int first = min_heap.top();
    min_heap.pop();
    int second = min_heap.top();
    min_heap.pop();

    int mixed = first + second * 2;
    min_heap.push(mixed);
  }

  if (!min_heap.empty() && min_heap.top() >= K) {
    return answer;
  } else {
    return -1;
  }
}