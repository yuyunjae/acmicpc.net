#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

ll A, B;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B;
  queue<pair<ll, int>> qu;
  qu.emplace(A, 1);
  while (!qu.empty()) {
    pair<ll, int> p = qu.front();
    // cout << p.first << " " << p.second << endl;
    qu.pop();
    ll fir = p.first << 1;
    ll se = p.first * 10 + 1;
    if (fir == B || se == B) {
      cout << p.second + 1;
      return 0;
    }
    if (fir < B) qu.emplace(fir, p.second + 1);
    if (se < B) qu.emplace(se, p.second + 1);
  }
  cout << -1;
}