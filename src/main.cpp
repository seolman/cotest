#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
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

class DoubleQueue {
public:
  void push(int value) { ms.insert(value); }

  void pop_min() {
    if (!ms.empty()) {
      ms.erase(ms.begin());
    }
  }

  void pop_max() {
    if (!ms.empty()) {
      ms.erase(prev(ms.end()));
    }
  }

  int min() const {
    if (!ms.empty()) {
      return *ms.begin();
    }
    return 0;
  }

  int max() const {
    if (!ms.empty()) {
      return *ms.rbegin();
    }
    return 0;
  }

  bool empty() { return ms.empty(); }

private:
  multiset<int> ms;
};

vector<string> split(const string &input, const char &delimiter) {
  vector<string> result;
  stringstream ss(input);
  string segment;

  while (getline(ss, segment, delimiter)) {
    result.push_back(segment);
  }

  return result;
}

vector<int> solution(vector<string> operations) {
  DoubleQueue dpq;
  for (const auto &o : operations) {
    auto a = split(o, ' ');
    string code = a[0];
    int number = stoi(a[1]);
    if (code == "I") {
      dpq.push(number);
    } else if (code == "D") {
      if (dpq.empty()) {
        continue;
      }

      if (number == 1) {
        dpq.pop_max();
      } else {
        dpq.pop_min();
      }
    }
  }
  if (dpq.empty()) {
    return {0, 0};
  } else {
    return {dpq.max(), dpq.min()};
  }
}

int main() {
  vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
  vector<int> expected = {0, 0};
  vector<int> result = solution(operations);
  if (result == expected) {
    cout << "result: " << result << endl;
  } else {
    cout << "expected: " << expected << ", " << "result: " << result << endl;
  }
  return 0;
}
