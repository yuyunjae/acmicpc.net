/*
    sol 4m/s
    트리의 지름을 구하는 방법을 외워두자!
    1. 트리에서 임의의 노드를 선택하고 해당 노드로 부터 가장 멀리있는 노드를 찾는다.
    2. 1에서 찾은 가장 멀리있는 노드를 기준으로 다시 해당 노드로 부터 가장 멀리있는 노드까지의 거리를 구한다.
    3. 2에서 구한 거리가 트리의 지름이다.
    머리속에서 증명해봅시다! 화이팅!
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int> > tree[10001];
bool visit[10001];
int max_cost, far_node;

void    dfs(int start, int distance)
{
    for (auto i : tree[start])
    {
        if (!visit[i.first])
        {
            visit[i.first] = true;
            dfs(i.first, distance + i.second);
            visit[i.first] = false;
        }
    }
    if (max_cost < distance)
    {
        max_cost = distance;
        far_node = start;
    }
}

int main(void)
{
    int n, parent, child, cost;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> parent >> child >> cost;
        tree[parent].emplace_back(child, cost);
        tree[child].emplace_back(parent, cost);
    }
    visit[1] = true;
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    visit[far_node] = true;
    dfs(far_node, 0);
    cout << max_cost;
}