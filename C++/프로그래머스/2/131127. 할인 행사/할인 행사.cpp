#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  map<string, int> wanted_map;
  for (int i = 0; i < want.size(); i++) {
    wanted_map[want[i]] = number[i];
  }

  for (int i = 0; i < (int)discount.size() - 10 + 1; i++) {
    map<string, int> discount_map;
    
    for (int j = i; j < i + 10; j++) {
      discount_map[discount[j]]++;
    }

    if (discount_map == wanted_map) {
      answer++;
    }
  }

  return answer;
}