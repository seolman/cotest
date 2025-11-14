#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  unordered_map<string, int> clothes_map;
  for (const auto &cloth_pair : clothes) {
    clothes_map[cloth_pair[1]]++;
  }
  int answer = 1;
  for (const auto &pair : clothes_map) {
    answer *= (pair.second + 1);
  }
  return answer - 1;
}
