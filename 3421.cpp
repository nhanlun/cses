#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

long long add(long long a, long long b, long long mod) {
  auto tmp = a + b;
  if (tmp > mod) {
    tmp -= mod;
  }
  return tmp;
}

long long mult(long long a, long long b, long long mod) {
  if (b == 1) {
    return a % mod;
  }
  auto tmp = mult(a, b / 2, mod) * 2 % mod;
  return (b % 2 == 0) ? tmp : add(tmp, a, mod);
}

long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  auto tmp = power(a, b / 2, mod);
  tmp = mult(tmp, tmp, mod);
  return (b % 2 == 0) ? tmp : mult(tmp, a, mod);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> m;
  // map<int, int> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]]++;
  }
  long long MOD = 1000000007;
  long long cur = 1;
  long long res = 0;
  for (auto [u, v] : m) {
    res = add(res, mult(cur, v, MOD), MOD);
    cur = mult(cur, v + 1, MOD);
  }
  // for (int i = 0; i < n; ++i) {
  //   auto tmp = m[a[i]];
  //   auto tmp2 = power(tmp + 1, MOD - 2, MOD);
  //   cur = mult(cur, tmp2, MOD);
  //   res = add(res, cur, MOD);
  //   m[a[i]]++;
  //   cur = mult(cur, tmp + 2, MOD);
  // }
  cout << res << '\n';
  return 0;
}