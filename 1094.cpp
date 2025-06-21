#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long res = 0;
  int cur = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    if (x < cur) {
      res += cur - x;
    } else {
      cur = x;
    }
  }
  cout << res;
  return 0;
}