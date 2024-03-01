#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void    bfs(int A, int B) // sol 3268m/s
{
    queue<pair<int, string> > qu;
    bool visit[10000] = {0, };
    int val, D, S, L, R;
    string str = "";
    
    qu.emplace(A, "");
    while (!qu.empty())
    {
        val = qu.front().first;
        str = qu.front().second;
        qu.pop();

        if (val == B)
            break ;
        D = val * 2 % 10000;
        S = (val > 0 ? val - 1 : 9999);
        L = val * 10 % 10000 + val / 1000;
        R = val / 10 + 1000 * (val % 10);
        if (!visit[D])
        {
            visit[D] = true;
            qu.emplace(D, str + 'D');
        }
        if (!visit[S])
        {
            visit[S] = true;
            qu.emplace(S, str + 'S');
        }
        if (!visit[L])
        {
            visit[L] = true;
            qu.emplace(L, str + 'L');
        }
        if (!visit[R])
        {
            visit[R] = true;
            qu.emplace(R, str + 'R');
        }
    }
    cout << str << '\n';
}

int main(void)
{
    int T, A, B;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        bfs(A, B);
    }
}


/* // 지리는 풀이.. 628m/s 문자열을 queue에 넣지 않고 visit배열과 m배열을 이용해 아름답게 풀었다..
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int visit[10101];
char m[10101];
int a, b;

void print(int x){
    if(x==a) return;
    print(visit[x]-1);
    printf("%c", m[x]);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        queue<int> q;
        q.push(a);
        while(!q.empty()){
            int x=q.front(); q.pop();
            int d=x*2%10000;
            int s=x?x-1:9999;
            int l=x/1000+x%1000*10;
            int r=x/10+x%10*1000;
            if(d==b){print(x); printf("D\n"); break;}
            if(s==b){print(x); printf("S\n"); break;}
            if(l==b){print(x); printf("L\n"); break;}
            if(r==b){print(x); printf("R\n"); break;}
            if(!visit[d]){q.push(d); visit[d]=x+1; m[d]='D';}
            if(!visit[s]){q.push(s); visit[s]=x+1; m[s]='S';}
            if(!visit[l]){q.push(l); visit[l]=x+1; m[l]='L';}
            if(!visit[r]){q.push(r); visit[r]=x+1; m[r]='R';}
        }
        memset(visit, 0, sizeof(visit));
        memset(m, 0, sizeof(m));
    }
}
*/
