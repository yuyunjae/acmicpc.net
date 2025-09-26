// bfs
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int T, M, N, K;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b, answer = 0;
    bool map[50][50]{};
    bool visit[50][50]{};
    queue<pair<int, int>> qu;
    cin >> M >> N >> K;
    for (int j = 0; j < K; j++) {
      cin >> a >> b;
      map[a][b] = true;
    }
    for (int j = 0; j < M; j++) {
      for (int l = 0; l < N; l++) {
        if (map[j][l] && !visit[j][l]) {
          qu.emplace(j, l);
          visit[j][l] = true;
          answer++;
          while (!qu.empty()) {
            pair<int, int> p = qu.front();
            qu.pop();
            for (int s = 0; s < 4; s++) {
              int x = dx[s] + p.first;
              int y = dy[s] + p.second;
              if (x >= 0 && y >= 0 && x < M && y < N && !visit[x][y] &&
                  map[x][y]) {
                visit[x][y] = true;
                // cout << x << " " << y << endl;
                qu.emplace(x, y);
              }
            }
          }
        }
      }
    }
    cout << answer << "\n";
  }
}

/*
// 누군가가 dfs로 푼 것 깔끔함.
#include<stdio.h>

bool map[51][51] = {{false,}};


void dfs(int x, int y){
    if (x<0) return;
    if (y<0) return;
    if (!map[x][y]) return;
    map[x][y] = false;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    return;
}

void f(){
    int w,h,k;
    scanf("%d %d %d",&w, &h, &k);

    int x,y;
    for (int i=0;i<k;i++){
        scanf("%d %d", &x, &y);
        map[x][y] = true;
    }

    int res = 0;
    for (int x=0;x<w;x++){
        for(int y=0;y<h;y++){
            if (map[x][y]){
                res++;
                dfs(x,y);
            }
        }
    }

    printf("%d\n",res);
}


int main(){
        int t;
        scanf("%d", &t);
    while(t--) f();
}
*/