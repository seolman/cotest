#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    os << *it;
    if (it != vec.end() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs,
             int startday) {
  int answer = 0;
  int n = schedules.size();

  for (int i = 0; i < n; i++) {
    bool flag = true;
    int schedule = schedules[i];
    int deadline_h = schedule / 100;
    int deadline_m = (schedule % 100) + 10;

    if (deadline_m >= 60) {
      deadline_h += deadline_m / 60;
      deadline_m %= 60;
    }

    int deadline_t = deadline_h * 100 + deadline_m;

    printf("i: %d\n", i);
    printf("deadline: %d\n", deadline_t);
    for (int j = 0; j < 7; j++) {
      int weekday_idx = (startday - 1 + j) % 7;
      if (weekday_idx >= 0 && weekday_idx <= 4) {
        int log_time = timelogs[i][j];
        if (log_time > deadline_t) {
          flag = false;
          printf("logtime: %d > %d: deadline_t\n", log_time, deadline_t);
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

int main() {
  cout << "TESTING" << endl;
  vector<int> schedules = {700, 800, 1100};
  vector<vector<int>> timelogs = {{710, 2359, 1050, 700, 650, 631, 659},
                                  {800, 801, 805, 800, 759, 810, 809},
                                  {1105, 1001, 1002, 600, 1059, 1001, 1100}};
  int startday = 5;
  int expected = 3;
  int result = solution(schedules, timelogs, startday);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  schedules = {730, 855, 700, 720};
  timelogs = {{710, 700, 650, 735, 700, 931, 912},
              {908, 901, 805, 815, 800, 831, 835},
              {705, 701, 702, 705, 710, 710, 711},
              {707, 731, 859, 913, 934, 931, 905}};
  startday = 1;
  expected = 2;
  result = solution(schedules, timelogs, startday);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "FAILED" << endl;
    cout << "expected: " << expected << endl;
    cout << "result: " << result << endl;
  }
  return 0;
}
