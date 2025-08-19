#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M;
string map[1000];
int visit[1000][1000];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

int bfs(int n, int m, int idx) {
  int count = 1;
  queue<pair<int, int>> qu;
  qu.emplace(n, m);
  while (!qu.empty()) {
    pair<int, int> state = qu.front();
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int x = state.first + dx[i];
      int y = state.second + dy[i];

      if (x > -1 && y > -1 && x < N && y < M && !visit[x][y] &&
          map[x][y] == '0') {
        visit[x][y] = idx;
        count++;
        qu.emplace(x, y);
      }
    }
  }
  return count;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> check_vec;
  check_vec.push_back(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> map[i];
  }

  int checkIdx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visit[i][j] && map[i][j] == '0') {
        visit[i][j] = ++checkIdx;
        check_vec.push_back(bfs(i, j, checkIdx));
      }
    }
  }

  //   for (int i = 0; i < N; i++) {
  //     for (int j = 0; j < M; j++) {
  //       cout << visit[i][j];
  //     }
  //     cout << '\n';
  //   }
  //   for (auto i : check_vec) cout << i;

  // output
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] == '1') {
        int count = 1;
        unordered_set<int> uSet;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];

          if (x > -1 && y > -1 && x < N && y < M && map[x][y] == '0' &&
              uSet.find(visit[x][y]) == uSet.end()) {
            count += check_vec[visit[x][y]];
            uSet.insert(visit[x][y]);
          }
        }
        cout << count % 10;
      } else
        cout << 0;
    }
    cout << '\n';
  }
  return 0;
}
