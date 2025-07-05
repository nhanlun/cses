#include <deque>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  deque<int> q;
  map<int, int> m;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    while (!q.empty() && m.count(a[i]) > 0) {
      m[q.front()]--;
      if (m[q.front()] == 0) {
        m.erase(q.front());
      }
      q.pop_front();
    }
    q.push_back(a[i]);
    m[a[i]]++;
    res += q.size();
    // cerr << i << ' ' << res << '\n';
  }
  cout << res << '\n';
  return 0;
}