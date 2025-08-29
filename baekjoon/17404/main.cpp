// dp를 생각하긴했으나, 순환부분을 어떻게 처리할지 몰라서 어려웠다.
// 선택한 색깔(첫번쨰집)을 제외한 나머지를 INF(1e7)값으로 넣어두고 dp를 수행한
// 후에, 만약 마지막 집의 색깔이 처음과 같다면, 해당 경우를 최솟값 계산에
// 제외하는 방식으로 해결하면 된다.
#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int cost[1000][3]{};
  int dp[1000][3]{};
  int N;
  int result = 2147483647;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }
  for (int col = 0; col < 3; col++) {
    for (int j = 0; j < 3; j++) {
      if (col == j)
        dp[0][j] = cost[0][j];
      else
        dp[0][j] = 1e7;  // 첫 번째집이 선택한 색깔이 아닌 경우는 dp괴정에서
                         // 선택받지 못하도록 INF에 가까운 값을 넣어줌.
    }
    for (int i = 1; i < N; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
      dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + cost[i][1];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
      //   cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    for (int i = 0; i < 3; i++) {
      if (i == col)  // 1 번째 집과 N 번째 집이 색깔이 같은 경우는 제외.
        continue;
      else
        result = min(result, dp[N - 1][i]);
    }
    // 1번째 집이 R이면, G와 B에는 dp[0]에 INF를 넣어서 선택 받지 못하도록 하고,
    // 최종 결과에서 N번째 집이 R인 경우를 제외함으로써 R -> G, R -> B인 경우만
    // 최종값 계산에 참여
    // 1번째 집이 G면, G -> R, G -> B만 참여하게됨. 1번째 집이 ㅠ인 경우도
    // 마찬가지.

    // 첫 번째 집이 R일떄, G,B 배열에는 INF를 넣어주는것이 핵심인듯..
  }
  cout << result;
}