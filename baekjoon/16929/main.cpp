// bfs로 해결. 이전 방향을 계속 기억하는 형태로 진행.
// 만약 curr_state가 동일한 값을 만나면 cycle발생.
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string str[50];
int visit[50][50];
queue<vector<int>> qu;
int curr_state = 0;
int N, M;

bool bfs() {
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  while (!qu.empty()) {
    vector<int> a = qu.front();
    qu.pop();
    int x, y;
    for (int i = 0; i < 4; i++) {
      if (i == a[2]) continue;
      x = a[1] + dx[i];
      y = a[0] + dy[i];
      if (x > -1 && y > -1 && x < M && y < N && str[a[0]][a[1]] == str[y][x]) {
        if (visit[y][x] == curr_state) {
          cout << "Yes";
          return true;
        }
        visit[y][x] = curr_state;
        qu.push({y, x, (i + 2) % 4});
      }
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> str[i];
  //   for (int i = 0; i < N; i++) cout << str[i] << endl;

  // visit 초기화.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visit[i][j] = 20000;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visit[i][j] > curr_state) {
        qu.push({i, j, 0});
        visit[i][j] = curr_state;
        if (bfs()) return 0;
      }
      curr_state++;
    }
  }

  cout << "No";
  return 0;
}