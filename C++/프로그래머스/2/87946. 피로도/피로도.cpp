#include <algorithm>
#include <vector>

using namespace std;
int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;
  sort(dungeons.begin(), dungeons.end());
  do {
    int current_k = k;
    int count = 0;
    for (const auto &dungeon : dungeons) {
      int required = dungeon[0];
      int use = dungeon[1];
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

