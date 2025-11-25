#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
  sort(times.begin(), times.end());
  long long low = 1;
  long long high = (long long)n * times.back();
  long long answer = high;

  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long processed = 0;

    for (const auto &time : times) {
      processed += mid / time;

      if (processed >= n) {
        break;
      }
    }

    if (processed >= n) {
      answer = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return answer;
}
