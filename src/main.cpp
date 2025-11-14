#include <algorithm>
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

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;
  // next_permutation()은 오름차순 정렬이 되야함?
  sort(dungeons.begin(), dungeons.end());
  do {
    int current_k = k;
    int count = 0;
    cout << dungeons << endl;
    for (const auto &dungeon : dungeons) {
      int required = dungeon[0];
      int use = dungeon[1];
      cout << "current k: " << current_k << ", " << "required: " << required << endl;
      if (current_k >= required) {
        current_k -= use;
        count++;
      } else {
        break;
      }
    }

    answer = max(count, answer);
  } while (next_permutation(dungeons.begin(), dungeons.end()));
  return answer;
}

int main() {
  int k = 80;
  vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
  int expected = 3;
  int result = solution(k, dungeons);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
