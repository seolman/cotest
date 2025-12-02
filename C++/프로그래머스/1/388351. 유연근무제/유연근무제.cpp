#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs,
             int startday) {
  int answer = 0;
  int n = schedules.size();

  for (int i = 0; i < n; i++) {
    bool flag = true;
    int schedule = schedules[i];
    int deadline_m = schedule % 100 + 10;
    int deadline_h = schedule / 100;

    if (deadline_m >= 60) {
      deadline_h += deadline_m / 60;
      deadline_m %= 60;
    }

    int deadline_t = deadline_h * 100 + deadline_m;

    for (int j = 0; j < 7; j++) {
      int weekday_idx = (startday - 1 + j) % 7;
      if (weekday_idx >= 0 && weekday_idx <= 4) {
        int log_time = timelogs[i][j];
        if (log_time > deadline_t) {
          flag = false;
          break;
        }
      }
    }

    if (flag) {
      answer++;
    }
  }
  return answer;
}