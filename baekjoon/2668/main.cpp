#include <iostream>
#include <set>
// #include <vector>

using namespace std;

int arr[101];
int N;
set<int> ans;
set<int> temp;
int last;

bool find(int i) {
  if (ans.find(arr[i]) != ans.end()) return false;
  // cycle 찾음.
  if (temp.find(arr[i]) != temp.end()) {
    ans.insert(i);
    last = arr[i];
    return true;
  }
  temp.insert(arr[i]);
  if (find(arr[i])) {
    ans.insert(i);
    if (i == last) return false;
    return true;
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    if (arr[i] == i) ans.insert(i);
  }
  for (int i = 1; i <= N; i++) {
    if (ans.find(i) != ans.end()) continue;
    temp.insert(i);
    find(i);
    temp.clear();
  }
  cout << ans.size() << endl;
  for (auto i : ans) cout << i << endl;
  return 0;
}