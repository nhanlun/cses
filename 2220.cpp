#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
f[cur][x][free]

if (free or x < lim[cur]) {
  f[cur][x][free] += f[cur + 1][y][true]
}

if (not free and x == lim[cur]) {
  f[cur][x][free] += f[cur + 1][y][false]
}
*/
long long f[20][10][2][2];
bool visited[20][10][2][2];

long long calc(const vector<int> &lim, int cur, int x, bool free,
               bool leading) {
  if (visited[cur][x][free][leading]) {
    return f[cur][x][free][leading];
  }
  visited[cur][x][free][leading] = true;
  if ((not free) and x > lim[cur]) {
    return f[cur][x][free][leading] = 0;
  }
  if (cur == lim.size() - 1) {
    return f[cur][x][free][leading] = 1;
  }

  if (free or x <= lim[cur]) {
    for (int y = 0; y < 10; ++y) {
      if (y == x and x != 0) {
        continue;
      }
      if (y == x and x == 0 and not leading) {
        continue;
      }
      
      f[cur][x][free][leading] +=
          calc(lim, cur + 1, y, free or x < lim[cur], leading and x == 0 and y == 0);
    }
  }
  return f[cur][x][free][leading];
}

vector<int> split(long long a) {
  vector<int> res;
  while (a > 0) {
    res.emplace_back(a % 10);
    a /= 10;
  }
  res.emplace_back(0);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  long long a, b;
  cin >> a >> b;
  --a;
  auto va = split(a);
  auto vb = split(b);
  auto resA = a < 0 ? 0LL : calc(va, 0, 0, false, true);
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int z = 0; z < 2; ++z) {
          visited[i][j][k][z] = f[i][j][k][z] = 0;
        }
      }
    }
  }
  auto resB = calc(vb, 0, 0, false, true);
  cout << resB - resA;
  return 0;
}