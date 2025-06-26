#include <iostream>
#include <vector>

int main() {
  int test;
  std::cin >> test;
  while (test--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (a + b > n || a == n || b == n || (a + b == 1) ||
        (a == n - 1 && b != 1 && n > 1) || (a != 1 && b == n - 1 && n > 1) ||
        (n == 2 && a + b != 2 && a + b != 0)) {
      std::cout << "NO\n";
      continue;
    }
    int rem = n - a - b;
    std::vector<int> aa(n);
    std::vector<int> bb(n);
    for (int i = 1; i <= rem; ++i) {
      aa[i - 1] = i;
      bb[i - 1] = i;
    }
    if (b >= a) {
      for (int i = rem + 1; i <= n; ++i) {
        aa[i - 1] = i;
      }
      for (int i = 1; i <= b; ++i) {
        bb[i + rem - 1] = i + n - b;
      }
      for (int i = rem + b + 1; i <= n; ++i) {
        bb[i - 1] = i - b;
      }
    } else {
      for (int i = rem + 1; i <= n; ++i) {
        bb[i - 1] = i;
      }
      for (int i = 1; i <= a; ++i) {
        aa[i + rem - 1] = i + n - a;
      }
      for (int i = rem + a + 1; i <= n; ++i) {
        aa[i - 1] = i - a;
      }
    }
    for (int i = 0; i < n; ++i) {
      a -= (aa[i] > bb[i]);
      b -= (aa[i] < bb[i]);
    }
    if (a != 0 || b != 0) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      std::cout << aa[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
      std::cout << bb[i] << " ";
    }
    std::cout << "\n";
  }
}
/*
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 1

-> n-1 1

1 2 3 4 5 6 7 8 9 10
1 2 3 4 8 9 10 5 6 7

1 2 3
2 3 1
*/