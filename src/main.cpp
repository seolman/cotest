#include <functional>
#include <iostream>
#include <queue>
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

int main() {
  vector<int> scoville = {1, 2, 3, 9, 10, 12};
  int k = 7;
  int expected = 2;
  int result = solution(scoville, k);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
