#include <string>
#include <vector>

using namespace std;

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
