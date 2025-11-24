#include <iostream>
#include <queue>
#include <string>
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

int main() {
  string number = "1924";
  int k = 2;
  string expected = "94";
  string result = solution(number, k);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
