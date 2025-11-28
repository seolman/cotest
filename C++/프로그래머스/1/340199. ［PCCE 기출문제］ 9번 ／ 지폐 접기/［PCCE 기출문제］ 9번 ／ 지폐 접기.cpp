#include <string>
#include <vector>

using namespace std;
int solution(vector<int> wallet, vector<int> bill) {
  int answer = 0;
  int w_max = max(wallet[0], wallet[1]);
  int w_min = min(wallet[0], wallet[1]);
  while (true) {
    int bill_w = bill[0];
    int bill_h = bill[1];

    if ((bill_w <= w_max && bill_h <= w_min) ||
        (bill_h <= w_max && bill_w <= w_min)) {
      break;
    }

    if (bill_w >= bill_h) {
      bill[0] /= 2;
    } else {
      bill[1] /= 2;
    }
    answer++;
  }
  return answer;
}