#include <iostream>
#include <vector>

using namespace std;

void dfs(int pos, int n, vector<int> &cnt, string &res) {
  // cerr << "pos: " << pos << ", res: " << res << endl;
  if (pos == n) {
    cout << res << endl;
    exit(0);
  }
  for (int i = 0; i < cnt.size(); ++i) {
    if (cnt[i] > (n - pos + 1) / 2) {
      return;
    }
  }
  for (int i = 0; i < cnt.size(); ++i) {
    if (cnt[i] > 0 && (pos == 0 || res.back() != 'A' + i)) {
      cnt[i]--;
      res.push_back('A' + i);
      dfs(pos + 1, n, cnt, res);
      res.pop_back();
      cnt[i]++;
    }
  }
}

int main() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto i : s) {
    cnt[i - 'A']++;
  }
  string res;
  dfs(0, s.size(), cnt, res);
  cout << -1;
  return 0;
}