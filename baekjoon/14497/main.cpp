#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int map[301][301], N, M, junan[2], criminal[2], ans = 0;
    string temp;
    pair<int, int> point;
    queue<pair<int, int> > wave;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> junan[0] >> junan[1] >> criminal[0] >> criminal[1];
    for (int i = 1; i <= N; i++)
    {
        cin >> temp;
        for (int j = 1; j <= M; j++)
        {
            if (temp[j - 1] == '#')
                map[i][j] = 3;
            else if (temp[j - 1] == '*')
                map[i][j] = 2;
            else
                map[i][j] = temp[j - 1] - '0';
        }
        temp.clear();
    }
    while (true)
    {
        ans++;
        bool collapse[301][301] = {0, };
        wave.emplace(junan[0], junan[1]);
        // cout << wave.front().first << " " << wave.front().second << endl;
        while (!wave.empty())
        {
            point = wave.front();
            wave.pop();
            if (point.first - 1 > 0 && !collapse[point.first - 1][point.second])
            {
                if (!map[point.first - 1][point.second])
                    wave.emplace(point.first - 1, point.second);
                collapse[point.first - 1][point.second] = true;
            }
            if (point.first + 1 <= N && !collapse[point.first + 1][point.second])
            {
                if (!map[point.first + 1][point.second])
                    wave.emplace(point.first + 1, point.second);
                collapse[point.first + 1][point.second] = true;
            }
            if (point.second - 1 > 0 && !collapse[point.first][point.second - 1])
            {
                if (!map[point.first][point.second - 1])
                    wave.emplace(point.first, point.second - 1);
                collapse[point.first][point.second - 1] = true;
            }
            if (point.second + 1 <= M && !collapse[point.first][point.second + 1])
            {
                if (!map[point.first][point.second + 1])
                    wave.emplace(point.first, point.second + 1);
                collapse[point.first][point.second + 1] = true;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (collapse[i][j])
                {
                    if (map[i][j] == 3)
                    {
                        cout << ans;
                        return (0);
                    }
                    map[i][j] = 0;
                }
            }
        } 
    }
}