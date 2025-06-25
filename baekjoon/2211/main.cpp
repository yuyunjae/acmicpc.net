// dijkstra algorithm (priority_queue)
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct compareSecond {
  bool operator()(const vector<int>& a, const vector<int>& b) {
    return a[2] > b[2];
  }
};

priority_queue<vector<int>, vector<vector<int>>, compareSecond> qu;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  int A, B, C;
  cin >> N >> M;

  vector<vector<pair<int, int>>> vec(N + 1);
  vector<bool> visit(N + 1, false);
  vector<pair<int, int>> ans;
  unordered_set<int> un_set;
  for (int i = 2; i <= N; i++) un_set.insert(i);

  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    vec[A].push_back({B, C});
    vec[B].push_back({A, C});
  }

  for (auto i : vec[1]) qu.push({1, i.first, i.second});  // {front, to, cost}
  visit[1] = true;
  while (!qu.empty()) {
    vector<int> temp = qu.top();
    qu.pop();
    if (visit[temp[1]]) continue;
    visit[temp[1]] = true;
    ans.push_back({temp[0], temp[1]});
    un_set.erase(temp[1]);
    if (un_set.size() < 1) break;
    for (auto i : vec[temp[1]]) {
      if (!visit[i.first]) qu.push({temp[1], i.first, i.second + temp[2]});
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i.first << " " << i.second << '\n';
  }
  return 0;
}