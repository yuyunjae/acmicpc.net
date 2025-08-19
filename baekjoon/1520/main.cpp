#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501];
int M, N;

int find_path(int y, int x) {
  if (x < 1 || y < 1) {
    return (0);
  }
  if (y < M && map[y + 1][x] > map[y][x]) {
    if (dp[y + 1][x] > 0)
      dp[y][x] += dp[y + 1][x];
    else if (dp[y + 1][x] == 0)
      dp[y][x] += find_path(y + 1, x);
  }
  if (x < N && map[y][x + 1] > map[y][x]) {
    if (dp[y][x + 1] > 0)
      dp[y][x] += dp[y][x + 1];
    else if (dp[y][x + 1] == 0)
      dp[y][x] += find_path(y, x + 1);
  }
  if (y > 0 && map[y - 1][x] > map[y][x]) {
    if (dp[y - 1][x] > 0)
      dp[y][x] += dp[y - 1][x];
    else if (dp[y - 1][x] == 0)
      dp[y][x] += find_path(y - 1, x);
  }
  if (x > 0 && map[y][x - 1] > map[y][x]) {
    if (dp[y][x - 1] > 0)
      dp[y][x] += dp[y][x - 1];
    else if (dp[y][x - 1] == 0)
      dp[y][x] += find_path(y, x - 1);
  }
  if (dp[y][x] < 1) {
    dp[y][x] = -1;
    return (0);
  }
  return (dp[y][x]);
}

int main(void) {
  cin >> M >> N;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i <= M; i++) dp[i][0] = -1;
  for (int i = 0; i <= N; i++) dp[0][i] = -1;

  dp[1][1] = 1;
  find_path(M, N);
  if (dp[M][N] == -1)
    cout << 0;
  else
    cout << dp[M][N];
}