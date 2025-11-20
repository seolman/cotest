#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


bool is_prime(int num) {
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;

  for (int i = 3; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int solution(string numbers) {
  int answer = 0;
  unordered_set<int> unique_numbers;
  sort(numbers.begin(), numbers.end());
  do {
    for (int i = 1; i <= numbers.size(); i++) {
      string s = numbers.substr(0, i);
      unique_numbers.insert(stoi(s));
    }
  } while (next_permutation(numbers.begin(), numbers.end()));

  for (const int &n : unique_numbers) {
    if (is_prime(n)) {
      answer++;
    }
  }
  return answer;
}