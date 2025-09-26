#include <algorithm>
#include <iostream>

using namespace std;

typedef struct s_data {
  int wei;
  int tall;
} t_data;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  t_data pa[50]{};
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> pa[i].wei >> pa[i].tall;
  }
  for (int i = 0; i < N; i++) {
    int val = 1;
    for (int j = 0; j < N; j++) {
      if (i != j && pa[i].tall < pa[j].tall && pa[i].wei < pa[j].wei) {
        val++;
      }
    }
    cout << val << " ";
  }
}