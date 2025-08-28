// dfs - backtracking할때 visit 체크와 출력
// #include <iostream>
// #include <vector>

// using namespace std;

// int N, M;
// vector<int> vec[32001];
// bool visit[32001];

// void dfs(int i) {
//   for (auto idx : vec[i]) {
//     if (!visit[idx]) dfs(idx);
//   }
//   cout << i << " ";
//   visit[i] = true;
// }

// int main(void) {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);

//   cin >> N >> M;
//   for (int i = 0; i < M; i++) {
//     int a, b;
//     cin >> a >> b;
//     vec[b].push_back(a);
//   }
//   for (int i = 1; i <= N; i++) {
//     if (!visit[i]) dfs(i);
//   }
// }

// bfs - queue를 이용해서 답 넣고 반대로 출력
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  int in_degree[32001]{};
  vector<int> map[32001];
  queue<int> qu;
  vector<int> rev_ans;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    map[b].push_back(a);
    in_degree[a]++;
  }

  for (int i = 1; i <= N; i++) {
    if (!in_degree[i]) qu.push(i);
  }
  while (!qu.empty()) {
    int temp = qu.front();
    qu.pop();
    rev_ans.push_back(temp);
    for (auto i : map[temp]) {
      in_degree[i]--;
      if (in_degree[i] == 0) {
        qu.push(i);
      }
    }
  }
  for (int i = rev_ans.size() - 1; i >= 0; i--) cout << rev_ans[i] << " ";
}
