#include <iostream>

using namespace std;
using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll dp[100]{};

  int N;
  cin >> N;
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[N];
}