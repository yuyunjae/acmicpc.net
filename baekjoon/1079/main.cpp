// // 미완... 2% fail.. 왜지..
// #include <iostream>

// using namespace std;

//     int N, guilty[17], change_array[17][17], Eunjin, maxi, temp, temp_index;
//     bool death[17], flag;

// void dfs(int cnt, int depth)
// {
//     if (flag)
//         return ;
//     if (death[Eunjin] || cnt == 1)
//     {
//         maxi = max(maxi, depth);
//         if (cnt == 1)
//             flag = true;
//         return ;
//     }
//     if (cnt % 2) // 낮
//     {           
//         temp_index = -1;
//         temp = -1000;
//         for (int i = 0; i < N; i++)
//         {
//             if (temp < guilty[i] && !death[i])
//             {
//                 temp = guilty[i];
//                 temp_index = i;
//             }
//         }
//         death[temp_index] = true; 
//         dfs(cnt - 1, depth);
//         death[temp_index] = false;
//     }
//     else // 밤
//     {
//         for (int i = 0; i < N; i++)
//         {
//             if (i != Eunjin && !death[i])
//             {
//                 death[i] = true;
//                 for (int j = 0; j < N; j++)
//                     guilty[j] += change_array[i][j];
//                 // cout << "night death" << " " << i << ": " << cnt -1 << ": " << depth + 1 << endl;
//                 dfs(cnt - 1, depth + 1);
//                 if (flag)
//                     return ;
//                 for (int j = 0; j < N; j++)
//                     guilty[j] -= change_array[i][j];
//                 death[i] = false;
//             }
//         }
//     }
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N;
//     for (int i = 0; i < N; i++)
//         cin >> guilty[i];
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             cin >> change_array[i][j]; // i가 죽었을 때 j의 유죄지수의 변화량
//     }
//     cin >> Eunjin;
//     dfs(N, 0);
//     cout << maxi << endl;
// }


// 다른 분 코드
#include <iostream>
using namespace std;
typedef struct {
    int point;
    bool isDead;
}player;
 
int N, mafia, answer = 0;
bool flag;
player players[16];
int R[16][16];
 
// 현재 남은 인원, 보냈던 밤의 횟수
void game(int playerCnt, int round) {
    if (flag) return;
 
    // 마피아가 죽었거나 마지막까지 살아남았거나
    if (players[mafia].isDead || playerCnt == 1) {
        answer = answer < round ? round : answer;
        if (playerCnt == 1) flag = true;
        return;
    }
 
    if (playerCnt % 2) { // 낮
        int target = 0;
        int maxPoint = 0;
        for (int i = 0; i < N; i++) {
            // 이미 죽은 사람인 경우
            if (players[i].isDead)
                continue;
            if (players[i].point > maxPoint) {
                target = i;
                maxPoint = players[i].point;
            }
        }
 
        players[target].isDead = true;
        game(playerCnt - 1, round);
        players[target].isDead = false;
    }
        
    else { // 밤
        for (int i = 0; i < N; i++) {
            // 이미 죽었거나 마피아 본인인 경우
            if (players[i].isDead || i == mafia) continue;
 
            // 유죄지수 갱신
            for (int j = 0; j < N; j++)
                players[j].point = players[j].point + R[i][j];
            players[i].isDead = true;
 
            game(playerCnt - 1, round + 1);
 
            // 유죄지수 원복
            for (int j = 0; j < N; j++)
                players[j].point = players[j].point - R[i][j];
            players[i].isDead = false;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> players[i].point;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> R[i][j];
    
    cin >> mafia;
 
    game(N, 0);
 
    cout << answer << endl;
    return 0;
}