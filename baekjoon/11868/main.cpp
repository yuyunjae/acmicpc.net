// 미완 스프라그-그런디 정리 공부하기
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void)
{
    int N, st, stone[100], set_size, cnt;
    set<int> se;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> st;
        if (se.find(st) != se.end())
            se.erase(st);
        else
            se.insert(st);
    }
    sort(stone, stone + N);
    set_size = se.size();
    if (set_size == 0)
        cout << "cubelover";
    else if (set_size == 1 || set_size == 2)
        cout << "koosaga";
    else
    {
        cnt = set_size;
        for (auto i : se)
        {
            if (i <= set_size)
                cnt--;
        }
        if ((cnt + set_size) % 2)
            cout << "cubelover";
        else
            cout << "koosaga";
    }
}