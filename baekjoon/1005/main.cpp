// dfs
// #include <iostream>
// #include <vector>

// using namespace std;
// int T, N, K, goal;
// vector<long long> delay;
// vector<long long> con_seq[1001];
// long long dp[1001];

// long long dfs(int obj) {
//   if (dp[obj] != -1) return dp[obj];
//   for (auto i : con_seq[obj]) {
//     dp[obj] = max(dfs(i), dp[obj]);
//   }
//   if (dp[obj] == -1) dp[obj]++;
//   dp[obj] += delay[obj];
//   return dp[obj];
// }

// int main(void) {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);

//   cin >> T;
//   for (int i = 0; i < T; i++) {
//     delay.clear();
//     for (auto &i : con_seq) i.clear();
//     for (int i = 0; i < 1001; i++) dp[i] = -1;
//     cin >> N >> K;
//     delay.push_back(0);
//     for (int i = 0; i < N; i++) {
//       int d_temp;
//       cin >> d_temp;
//       delay.push_back(d_temp);
//     }
//     for (int i = 0; i < K; i++) {
//       int a, b;
//       cin >> a >> b;
//       con_seq[b].push_back(a);
//     }
//     cin >> goal;
//     cout << dfs(goal) << '\n';
//   }
// }

// bfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int T, N, K, goal;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    vector<int> delay;
    vector<int> con_seq[1001];
    int degree[1001]{};
    long long dp[1001]{};
    cin >> N >> K;
    delay.push_back(0);
    for (int i = 1; i <= N; i++) {
      int d_temp;
      cin >> d_temp;
      delay.push_back(d_temp);
      dp[i] = d_temp;
    }
    for (int i = 0; i < K; i++) {
      int a, b;
      cin >> a >> b;
      con_seq[a].push_back(b);
      degree[b]++;
    }
    cin >> goal;
    queue<int> qu;
    for (int i = 1; i <= N; i++) {
      if (!degree[i]) {
        qu.push(i);
      }
    }
    while (!qu.empty()) {
      int point = qu.front();
      qu.pop();
      for (auto i : con_seq[point]) {
        degree[i]--;
        dp[i] = max(dp[i], dp[point] + delay[i]);
        if (!degree[i]) qu.push(i);
      }
    }
    cout << dp[goal] << '\n';
  }
}