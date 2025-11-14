#include <algorithm>
#include <iostream>
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

bool solution(vector<string> phone_book) {
  bool answer = true;
  sort(phone_book.begin(), phone_book.end());
  for (int i = 0; i < phone_book.size() - 1; i++) {
    if (phone_book[i + 1].find(phone_book[i], 0) == 0) {
      answer = false;
      break;
    }
  }
  return answer;
}

int main() {
  vector<string> phone_book = {"119", "97674223", "1195524421"};
  bool expected = false;
  bool result = solution(phone_book);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  phone_book = {"123", "456", "789"};
  expected = true;
  result = solution(phone_book);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }

  phone_book = {"12", "123", "1235", "567", "88"};
  expected = false;
  result = solution(phone_book);

  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
