#include <deque>
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

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int total_weight = 0;
  deque<int> trucks(truck_weights.begin(), truck_weights.end());
  deque<int> bridge(bridge_length, 0);

  while (!trucks.empty()) {
    answer++;

    total_weight -= bridge.front();
    bridge.pop_front();

    if (trucks.front() + total_weight <= weight) {
      int new_truck = trucks.front();
      trucks.pop_front();

      bridge.push_back(new_truck);
      total_weight += new_truck;
    } else {
      bridge.push_back(0);
    }
  }

  return answer + bridge_length;
}

int main() {
  int bridge_length = 2;
  int weight = 10;
  vector<int> truck_weights = {7, 4, 5, 6};
  int expected = 8;
  int result = solution(bridge_length, weight, truck_weights);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  bridge_length = 100;
  weight = 100;
  truck_weights = {10};
  expected = 101;
  result = solution(bridge_length, weight, truck_weights);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  bridge_length = 100;
  weight = 100;
  truck_weights = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  expected = 110;
  result = solution(bridge_length, weight, truck_weights);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
