#include <string>
#include <vector>
#include <deque>

using namespace std;
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