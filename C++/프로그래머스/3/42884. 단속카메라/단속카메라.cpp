#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
  sort(routes.begin(), routes.end(), cmp);
  int answer = 1;
  int cam_pos = routes[0][1];

  for (int i = 1; i < routes.size(); i++) {
    if (routes[i][0] > cam_pos) {
      answer++;
      cam_pos = routes[i][1];
    }
  }

  return answer;
}
