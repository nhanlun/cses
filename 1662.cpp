#include <iostream>
#include <map>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long sum = 0;
  std::map<long long, long long> cnt;
  cnt[0] = 1;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      auto tmp = abs(a[i]) / n;
      a[i] = (a[i] + n * (tmp + 10)) % n;
    }
    sum = (sum + a[i]) % n;
    res += cnt[sum];
    cnt[sum]++;
  }
  std::cout << res;
  return 0;
}
