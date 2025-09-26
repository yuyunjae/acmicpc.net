#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, count[5];
  string s;

  cin >> N;
  for (int i = 0; i < 4; i++) cin >> count[i];
  cin >> s;
  if (s.length() == 1 && s[0] == 'a' && count[0] > 0) {
    cout << "Yes";
    return 0;
  }
  if (s[0] != 'a' || s[s.length() - 1] != 'a' || count[0] < 2) {
    cout << "No";
    return 0;
  }
  count[0] -= 1;
  for (int i = 0; i < s.length() - 1; i++) {
    count[s[i] - 'a'] -= 1;
    if (s[i] == s[i + 1] || count[s[i] - 'a'] < 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}