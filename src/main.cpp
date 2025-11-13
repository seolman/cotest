#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

  for (int i = 0; i < arr1.size(); i++) {
    for (int j = 0; j < arr2[0].size(); j++) {
      for (int k = 0; k < arr1[0].size(); k++) {
        answer[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  return answer;
}

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

int main() {
  vector<vector<int>> arr1 = {{1, 4}, {3, 2}, {4, 1}};
  vector<vector<int>> arr2 = {{3, 3}, {3, 3}};
  vector<vector<int>> expected = {{15, 15}, {15, 15}, {15, 15}};
  vector<vector<int>> result = solution(arr1, arr2);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
