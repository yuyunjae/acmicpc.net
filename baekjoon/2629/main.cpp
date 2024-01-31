#include <iostream>

using namespace std;

int weight[31];
bool dp[31][15001];
int num;

void    solve(int i, int wei)
{
    //cout << i << " : " << wei << '\n';
    if (i > num || dp[i][wei]) return ;
    dp[i][wei] = true;
    solve(i + 1, wei + weight[i]); // 무게 + 
    solve(i + 1, abs(wei - weight[i])); // 무게 -, 또는 반대
    solve(i + 1, wei); // 해당 추 저울 x
}

int main(void)
{
    int count, marble;

    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> weight[i];
    solve(0, 0);

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> marble;
        if (marble <= 15000 && dp[num][marble])
            cout << "Y ";
        else
            cout << "N ";
    }
}