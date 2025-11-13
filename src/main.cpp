#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 0;
  return answer;
}

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

void pick(int n, vector<int>& picked, int to_pick) {
  if (to_pick == 0) {
    cout << picked << endl;
    return;
  }
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  for (int next = smallest; next < n; next++) {
    picked.push_back(next);
    pick(n, picked, to_pick - 1);
    picked.pop_back();
  }
}

int main() {
  vector<vector<string>> clothes = {{"yellow_hat", "headgear"},
                                    {"blue_sunglasses", "eyewear"},
                                    {"green_turban", "headgear"}};
  int expected = 5;
  int result = solution(clothes);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  vector<int> arr = {};
  int n = 7;
  pick(n, arr, 4);
  return 0;
}
