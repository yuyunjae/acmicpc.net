#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, double>& a, const pair<int, double>& b){
        return a.second > b.second;
    }
};

priority_queue<pair<int, double>, vector<pair<int, double> >, Compare > pq;
bool visit[10001];
double point[100][2];


int main(void)
{
    int n;
    double ans = 0;
    pair<int, double> val;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> point[i][0] >> point[i][1];
    
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        val = pq.top();
        pq.pop();
        if (visit[val.first]) continue;
        visit[val.first] = true;
        ans += sqrt(val.second);
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
                pq.emplace(i, (point[val.first][0] - point[i][0]) * (point[val.first][0] - point[i][0]) + (point[val.first][1] - point[i][1]) * (point[val.first][1] - point[i][1]));
        }
    }
    cout << ans;
}


// #include <iostream>
// #include <cmath>
// #include <vector>

// using namespace std;

// bool visit[10001];
// double point[100][2];
// double distance_2[100]; // distance * distance

// int main(void)
// {
//     int n, val = 0, temp;
//     double mini, ans = 0;

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> point[i][0] >> point[i][1];
//         distance_2[i] = 1e9;
//     }
//     visit[0] = true;

//     for (int i = 1; i < n; i++)
//     {
//         mini = 1e9 + 10;
//         for (int j = 1; j < n; j++)
//         {
//             if (!visit[j])
//             {
//                 distance_2[j] = min(distance_2[j], (point[val][0] - point[j][0]) * (point[val][0] - point[j][0]) + (point[val][1] - point[j][1]) * (point[val][1] - point[j][1]));
//                 if (distance_2[j] < mini)
//                 {
//                     temp = j;
//                     mini = distance_2[j];
//                 }
//             }
//         }
//         val = temp;
//         visit[val] = true;
//         ans += sqrt(distance_2[val]);
//     }
//     cout << ans;
// }
