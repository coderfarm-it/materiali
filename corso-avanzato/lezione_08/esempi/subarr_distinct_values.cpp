#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  int cnt = 0;
  map<int, int> frq;
  for (int i = 0, j = -1; i < n; ++i) {
    cnt += ++frq[a[i]] == 1;
    while (cnt > k) {
      cnt -= --frq[a[++j]] == 0;
    }
    ans += i - j;
  }
  cout << ans << "\n";
}
