#include <string>
#include <vector>

using namespace std;

int solution(string name) {
  int answer = 0;
  for (const auto &c : name) {
    answer += min(c - (int)'A', (int)'Z' - c + 1);
  }

  const int n = name.length();
  int min_hor = n - 1;
  for (int i = 0; i < n; i++) {
    int next_idx = i + 1;

    while (next_idx < n && name[next_idx] == 'A') {
      next_idx++;
    }
    int turnaround = i + (n - next_idx) + min(i, n - next_idx);
    min_hor = min(min_hor, turnaround);
  }

  return answer + min_hor;
}