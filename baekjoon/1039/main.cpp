#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

int N, K, M;

typedef struct s_pq {
  bool operator()(pair<string, vector<int>> a, pair<string, vector<int>> b) {
    if (a.second[0] != b.second[0])
      return a.second[0] >= b.second[0];
    else
      return a.first < b.first;
  }
} t_pq;

priority_queue<pair<string, vector<int>>, vector<pair<string, vector<int>>>,
               t_pq>
    pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string num;

  cin >> num >> K;
  N = stoi(num);
  M = num.length();

  if (N < 10 || (N < 100 && N % 10 == 0))
    cout << -1;
  else {
    pq.emplace(num, vector<int>{0, 0});
    while (!pq.empty()) {
      pair<string, vector<int>> p = pq.top();
      //   cout << p.first << " " << p.second << endl;
      pq.pop();
      if (p.second[0] >= K) {
        cout << p.first;
        return 0;
      }
      int idx = p.second[1];
      if (idx >= M - 1) {
        set<int> s(p.first.begin(), p.first.end());
        if (s.size() != p.first.size()) {
          cout << p.first;
          return 0;
        }
        // cout << p.first << " " << p.second[0] << endl;

        while (p.second[0]++ < K) {
          swap(p.first[M - 2], p.first[M - 1]);
          //   cout << p.first << " " << p.second[0] << endl;
        }
        cout << p.first;
        return 0;
      }
      int max_ele = *max_element(p.first.begin() + idx, p.first.end());
      if (p.first[idx] == max_ele) {
        pq.emplace(p.first, vector<int>{p.second[0], idx + 1});
        continue;
      }
      for (int i = idx + 1; i < M; i++) {
        if (p.first[i] == max_ele) {
          string temp = p.first;
          swap(temp[i], temp[idx]);
          pq.emplace(temp, vector<int>{p.second[0] + 1, idx + 1});
        }
      }
    }
  }
}