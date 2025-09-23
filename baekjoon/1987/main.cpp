// sol by dfs (376ms)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans;
int R, C;
bool visit[26];
vector<string> vec;
string temp;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

void dfs(int bx, int by, int point) {
  //   cout << bx << " " << by << " " << point << endl;
  for (int i = 0; i < 4; i++) {
    int x = bx + dx[i];
    int y = by + dy[i];

    if (x >= 0 && x < R && y >= 0 && y < C && visit[vec[x][y] - 'A'] == false) {
      visit[vec[x][y] - 'A'] = true;
      dfs(x, y, point + 1);
      visit[vec[x][y] - 'A'] = false;
    }
  }
  //   cout << ans << " " << point << endl;
  ans = max(ans, point);
  //   cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    cin >> temp;
    vec.push_back(temp);
  }
  ans = 1;
  visit[vec[0][0] - 'A'] = true;
  dfs(0, 0, 1);
  cout << ans;
}

/*
// same dfs but faster than me (20ms)
// memo를 이용해 이미 동일한 길을 지나왔으면 해당 경우를 무시하는 조건을
// 추가하여 더 빠름.
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int R, C;

vector<vector<int>> board;
vector<vector<int>> memo;

constexpr int DIR_SIZE = 4;
array<int, DIR_SIZE> dy = {-1, 1, 0, 0};
array<int, DIR_SIZE> dx = {0, 0, -1, 1};

int max_cnt = 0;

void dfs(int y, int x, int log, int cnt) {
  log |= (1 << board[y][x]);
  if (log == memo[y][x]) return; // 이미 계산한 경로

  max_cnt = max(max_cnt, cnt + 1);
  memo[y][x] = log;

  for (int i = 0; i < DIR_SIZE; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
    if (log & (1 << board[ny][nx])) continue; // board[ny][nx]의 알파벳이 이미
포함되어있음

    dfs(ny, nx, log, cnt + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  board.assign(R, vector<int>(C));
  memo.assign(R, vector<int>(C));

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      char ch;
      cin >> ch;
      board[i][j] = ch - 'A';
    }
  }

  dfs(0, 0, 0, 0);

  cout << max_cnt << '\n';

  return 0;
}
  */