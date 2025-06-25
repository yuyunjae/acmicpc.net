#include <iostream> // 아직 못풀음 방법 생각해야할듯.
#include <string>

using namespace std;

int N, M;
string str[50];

bool checkCycle(int xs, int ys, int xe, int ye, char ch)
{
    for (int i = ys + 1; i <= ye; i++)
    {
        if (str[xs][i] != ch)
            return false;
    }
    for (int i = xe + 1; i <= xs; i++)
    {
        if (str[i][ye] != ch)
            return false;
    }
    return true;
}

int main(void)
{
    int tempx, tempy;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0 ; i < N; i++){
        cin >> str[i];
    }
    for (int i = 0; i < N -1; i++)
    {
        for (int j = 0; j < M -1; j++)
        {
            tempx = i + 1;
            tempy = j + 1; 
            while (tempx < N && str[tempx][j] == str[i][j])
                tempx++;
            tempx--;
            if (tempx == i)
                break ;
            while (tempy < M && str[i][tempy] == str[i][j])
                tempy++;
            tempy--;
            if (tempy == j)
                break ;
            int k = min(tempx - i, tempy - j);
            for (int ind = 1; ind <= k; ind++)
            {
                if (str[i][j] == str[i+ind][j+ind])
                {
                    // if (checkCycle(i + ind, j, i, j + ind, str[i][j]))
                    // {
                    //     cout << "(" << i + ind << "," << j << ") : (" << i << "," << j + ind << ")\n";
                    //     cout << "YES";
                    //     return 0;
                    // }
                }
            }
        }
    }
    cout << "NO";
}