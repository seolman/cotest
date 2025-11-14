#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  unordered_map<string, int> clothes_map;
  for (const auto &cloth_pair : clothes) {
    clothes_map[cloth_pair[1]]++;
  }
  int answer = 1;
  for (const auto &pair : clothes_map) {
    // 안 입은 경우를 포함
    answer *= (pair.second + 1);
  }
  // 아무 것도 안입은 경우 -1
  return answer - 1;
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

  clothes = {{"crow_mask", "face"},
             {"blue_sunglasses", "face"},
             {"smoky_makeup", "face"}};
  expected = 3;
  result = solution(clothes);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
