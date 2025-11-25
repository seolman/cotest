#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  sort(rocks.begin(), rocks.end());
  int low = 1;
  int high = distance;
  int answer = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int removed = 0;
    int pos = 0;

    for (const auto &rock : rocks) {
      if (rock - pos < mid) {
        removed++;
      } else {
        pos = rock;
      }
    }

    if (distance - pos < mid) {
      removed++;
    }

    if (removed <= n) {
      answer = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return answer;
}