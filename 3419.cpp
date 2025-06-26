#include <iostream>
#include <vector>

using namespace std;

auto getMex(const vector<vector<int>> &a, int i, int j) {
  vector<bool> used(a.size() * 2 + 1, false);
  for (int k = 0; k < i; ++k) {
    used[a[k][j]] = true;
  }
  for (int k = 0; k < j; ++k) {
    used[a[i][k]] = true;
  }
  for (int k = 0; k < used.size(); ++k) {
    if (!used[k]) {
      return k;
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = getMex(a, i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}