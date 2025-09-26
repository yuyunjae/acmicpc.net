#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int K, temp;
  stack<int> st;
  ll answer = 0;

  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> temp;
    if (temp)
      st.push(temp);
    else
      st.pop();
  }
  while (!st.empty()) {
    answer += st.top();
    st.pop();
  }
  cout << answer;
}