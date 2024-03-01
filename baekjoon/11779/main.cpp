#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>

#define MAXI 2e10

using namespace std;

vector<pair<int, int> > bus[1001];
priority_queue<tuple<long long int, int, int>, vector<tuple<long long int, int, int> >, greater<tuple<long long int, int, int> > > q; // cost, arrive, city_count
long long int min_cost[1001];
int before[1001];

void    print_way(int depart, int arrive)
{
    if (arrive != depart)
        print_way(depart, before[arrive]);
    cout << arrive << " ";
}

int main(void) //dijkstra.... print_way is hard... should study again..
{
    int n, m, d, a, c, depart, arrive, start, city_count;
    long long int cost;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> d >> a >> c;
        bus[d].emplace_back(c, a);
    }
    cin >> depart >> arrive;
    for (int i = 1; i <= n; i++)
        sort(bus[i].begin(), bus[i].end());
    
    q.emplace(0, depart, 1);
    for(int i = 1; i <= n; i++)
        min_cost[i] = MAXI;
    min_cost[depart] = 0;

    while (!q.empty())
    {
        tie(cost, start, city_count) = q.top();
        q.pop();

        if (start == arrive)
        {
            cout << cost << '\n' << city_count << '\n';
            print_way(depart, arrive);
            return (0);
        }
        if (cost > min_cost[start])
            continue;
        for (auto i : bus[start])
        {
            if (min_cost[i.second] > cost + i.first)
            {
                min_cost[i.second] = cost + i.first;
                before[i.second] = start;
                q.emplace(i.first + cost, i.second, city_count + 1);
            }
        }
    }
}