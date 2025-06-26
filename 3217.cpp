#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<vector<bool>> used(n, vector<bool>(n, false));
  used[0][0] = true;
  queue<pair<int, int>> q;
  q.push({0, 0});
  int rr[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int cc[] = {1, 2, 2, 1, -1, -2, -2, -1};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 8; ++k) {
      auto u = i + rr[k];
      auto v = j + cc[k];
      if (u >= 0 && v >= 0 && u < n && v < n && !used[u][v]) {
        used[u][v] = true;
        a[u][v] = a[i][j] + 1;
        q.push({u, v});
      }
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