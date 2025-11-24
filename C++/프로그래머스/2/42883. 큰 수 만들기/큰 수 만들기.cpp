#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string number, int k) {
  string answer = "";
  for (const auto &c : number) {
    while (!answer.empty() && answer.back() < c && k > 0) {
      answer.pop_back();
      k--;
    }
    answer.push_back(c);
  }

  answer.erase(answer.length() - k, k);
  return answer;
}
