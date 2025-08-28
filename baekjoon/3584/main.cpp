#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int T, N;
int pointA, pointB;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    int arr[10001] = {
        0,
    };
    for (int j = 0; j < N - 1; j++) {
      int a, b;
      cin >> a >> b;
      arr[b] = a;
    }
    cin >> pointA >> pointB;
    unordered_set<int> se;
    se.insert(pointA);
    while (arr[pointA]) {
      se.insert(arr[pointA]);
      pointA = arr[pointA];
    }
    if (se.find(pointB) != se.end()) {
      cout << pointB << '\n';
      continue;
    }
    while (arr[pointB]) {
      if (se.find(arr[pointB]) != se.end()) {
        cout << arr[pointB] << '\n';
        break;
      }
      pointB = arr[pointB];
    }
  }
}

/*
다른 사람의 풀이. unordered_set대신에 배열을 사용해서 비슷한 효과를 냈음.
pointA, pointB를 체크해야하는 부분을 대신하기 위해서 par[0] = -1를 넣고,
반복문의 조건으로 par[p] != -1로 처리함. 코드도 간결해지고 훨씬 빨라짐.

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e4;
void solve() {
    int N;
    cin >> N;
    int par[N+1] = {}, color[N+1] = {};
    for (int i = 0; i < N-1; ++i) {
        int v, w;
        cin >> v >> w;
        par[w] = v;
    }
    int v, w;
    cin >> v >> w;

    int p = v; par[0] = -1;
    while (par[p] != -1) {
        color[p] = 1; p = par[p];
    }
    p = w;
    while (!color[p]) {
        p = par[p];
    }
    cout << p << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
*/
