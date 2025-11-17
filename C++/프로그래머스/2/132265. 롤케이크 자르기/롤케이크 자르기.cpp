#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;
  unordered_map<int, int> left_map;
  unordered_map<int, int> right_map;
  for (int t : topping) {
    right_map[t]++;
  }
  for (int t : topping) {
    left_map[t]++;
    right_map[t]--;
    if (right_map[t] == 0) {
      right_map.erase(t);
    }
    if (left_map.size() == right_map.size()) {
      answer++;
    }
  }
  return answer;
}
