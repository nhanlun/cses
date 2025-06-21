#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int res = 1; 
  for (int i = 0; i < s.length(); ++i) {
    if (i + 1 < s.length()) {
      int j;
      for (j = i + 1; j < s.length() and s[i] == s[j]; ++j);
      res = max(res, j - i);
      i = j - 1;
    }
  }
  cout << res << '\n';
  return 0;
}