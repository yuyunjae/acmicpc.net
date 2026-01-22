#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T{};
    cin >> T;
    for (int i = 1; i <= T; i++){
        int ans{}, temp{};
        for (int j= 0; j < 10; j++) {
            cin >> temp;
            ans += temp % 2 ? temp : 0;
        }
        cout << '#' << i << " " << ans << '\n';
    }
}   