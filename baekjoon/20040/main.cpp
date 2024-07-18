#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int point[500000];

pair<int, int> find_parent(int a, int level)
{
    if (point[a] == a) return make_pair(a, level);
    return find_parent(point[a], level + 1);
}

int main(void)
{
    int n, m, a, b, a_parent, b_parent, a_level, b_level, ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        point[i] = i;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        tie(a_parent, a_level) = find_parent(a, 0);
        tie(b_parent, b_level) = find_parent(b, 0);
        //cout << a_parent << " " << a_level << " " << b_parent << " " << b_level << endl;
        if (a_parent == b_parent && !ans)
        {
            ans = i;
            cout << ans;
        }
        if (a_parent != b_parent)
        {
            if (a_level > b_level)
                point[b_parent] = a_parent;
            else
                point[a_parent] = b_parent;
        }
    }
    if (!ans)
        cout << ans;
}