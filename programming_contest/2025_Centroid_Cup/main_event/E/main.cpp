#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int king[2];
int rock[2];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  vector<string> map;
  string temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    map.push_back(temp);
    for (int j = 0; j < N; j++) {
      if (temp[j] == 'K') {
        king[0] = i;
        king[1] = j;
      }
      if (temp[j] == 'R') {
        rock[0] = i;
        rock[1] = j;
        map[i][j] = 0;
      }
    }
  }
  queue<pair<int, int>> qu;
  qu.emplace(rock[0], rock[1]);
  while (!qu.empty()) {
    pair<int, int> pa = qu.front();
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int x = pa.first;
      int y = pa.second;
      while (true) {
        x += dx[i];
        y += dy[i];
        if (x >= 0 && y >= 0 && x < N && y < N && map[x][y] != 'B') {
          if (map[x][y] == '.') {
            map[x][y] = map[pa.first][pa.second] + 1;
            qu.emplace(x, y);
          }
        }
        // 미완
        else
          break;
      }
    }
  }
}