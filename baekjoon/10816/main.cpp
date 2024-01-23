#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mapset;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, val, M;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        if (mapset.find(val) != mapset.end())
            mapset[val] += 1;
        else
            mapset.insert({val, 1});
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        if (mapset.find(val) == mapset.end())
            cout << 0 << ' ';
        else
            cout << mapset.find(val)->second << ' ';
    }
}   