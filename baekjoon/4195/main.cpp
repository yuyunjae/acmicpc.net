#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, pair<string, int> > parent;

pair<string, int> find_root(string a)
{
    auto item = parent.find(a);
    if (a == item->second.first) return (item->second);

    return find_root(item->second.first);
}

int main(void)
{
    int t, F;
    string a, b;
    pair<string, int> a_parent, b_parent;
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> F;
        for (int i = 0; i < F; i++)
        {
            cin >> a >> b;
            if (parent.find(a) == parent.end())
                parent.emplace(a, make_pair(a, 1));
            if (parent.find(b) == parent.end())
                parent.emplace(b, make_pair(b, 1));
            a_parent = find_root(a);
            parent[a] = a_parent;
            b_parent = find_root(b);
            parent[b] = b_parent;

            if (a_parent != b_parent)
            {
                parent[b_parent.first] = make_pair(a_parent.first, b_parent.second);
                parent[a_parent.first] = make_pair(a_parent.first, a_parent.second + b_parent.second);
                cout << a_parent.second + b_parent.second << '\n';
            }
            else
                cout << a_parent.second << '\n';
        }
        parent.clear();
    }
}