#include <iostream>

using namespace std;

#define MAXVAL int(1e6)

int client_arr[1001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int C, N, cost, client;
  cin >> C >> N;

  for (int i = 1; i <= C; i++) client_arr[i] = MAXVAL;
  for (int i = 0; i < N; i++) {
    cin >> cost >> client;
    for (int j = 1; j <= C; j++) {
      if (j <= client) {
        client_arr[j] = min(cost, client_arr[j]);
        continue;
      }
      client_arr[j] = min(client_arr[j - client] + cost, client_arr[j]);
      //   cout << j << " : " << client_arr[j] << endl;
    }
  }
  cout << client_arr[C];
  return 0;
}