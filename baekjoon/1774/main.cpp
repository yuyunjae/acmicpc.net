// mst -> prim algorithm
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct s_rule {
  bool operator()(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;
  }
} t_rule;

long long point[1001][2];  // 점의 좌표
bool visit[1001];
double path[1001][1001];
double length;
double result = 0;
int N, M, X, Y;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  priority_queue<pair<double, int>, vector<pair<double, int>>, t_rule> pq;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> point[i][0] >> point[i][1];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (visit[i] && visit[j]) continue;
      length = sqrt((point[i][0] - point[j][0]) * (point[i][0] - point[j][0]) +
                    (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]));
      path[i][j] = length;
      path[j][i] = length;
    }
  }
  for (int i = 0; i < M;
       i++) {  // 처음에 이부분에서 visit로 처리했는데, visit처리한 각 군이 서로
               // 같은 군인지를 체크하지 못함. 따라서 해당 부분에서 오류 발생.
    cin >> X >> Y;
    path[X][Y] = 0;
    path[Y][X] = 0;
  }
  pq.emplace(0, X);
  int visit_count = 0;
  while (!pq.empty() && visit_count < N) {
    pair<double, int> temp = pq.top();
    pq.pop();
    if (visit[temp.second]) continue;
    // cout << temp.second << "  " << temp.first << endl;
    visit[temp.second] = true;
    visit_count++;
    result += temp.first;
    for (int i = 1; i <= N; i++) {
      if (!visit[i]) pq.emplace(path[temp.second][i], i);
    }
  }
  cout << fixed << setprecision(2);
  cout << result;
}