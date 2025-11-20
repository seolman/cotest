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

void dfs(vector<string> &dictionary, char vowels[], string word) {
  if (word.length() > 5) {
    return;
  }
  if (!word.empty()) {
    dictionary.push_back(word);
  }

  for (int i = 0; i < 5; i++) {
    dfs(dictionary, vowels, word + vowels[i]);
  }
}

int solution(string word) {
  char vowels[] = {'A', 'E', 'I', 'O', 'U'};
  vector<string> dictionary;

  dfs(dictionary, vowels, "");

  for (int i = 0; i < dictionary.size(); i++) {
    if (word == dictionary[i]) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  string word = "AAAAE";
  int expected = 6;
  int result = solution(word);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
