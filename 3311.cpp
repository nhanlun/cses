#include <iostream>
#include <vector>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<char>> a(m, vector<char>(n));

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      a[i][j] = s[j];
    }
  }
  vector<vector<char>> b(m, vector<char>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      bool used[4] = {false, false, false, false};
      if (i > 0) {
        used[b[i - 1][j] - 'A'] = true;
      }
      if (j > 0) {
        used[b[i][j - 1] - 'A'] = true;
      }
      used[a[i][j] - 'A'] = true;
      for (int k = 0; k < 4; ++k) {
        if (!used[k]) {
          b[i][j] = 'A' + k;
          break;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << b[i][j];
    }
    cout << endl;
  }
  return 0;
}