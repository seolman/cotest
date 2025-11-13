#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
  int answer = 0;
  int n = elements.size();
  vector<int> extended_elements = elements;
  extended_elements.insert(extended_elements.end(), elements.begin(),
                           elements.end());
  unordered_set<int> unique_sum;

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      int current_sum = accumulate(extended_elements.begin() + i,
                                   extended_elements.begin() + i + len, 0);
      unique_sum.insert(current_sum);
    }
  }
  answer = unique_sum.size();
  return answer;
}

int main() {
  vector<int> elements = {7, 9, 1, 1, 4};
  int expected = 18;
  int result = solution(elements);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
