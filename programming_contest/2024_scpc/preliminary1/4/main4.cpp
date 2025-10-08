// 70 / 350
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXI 2000000000
#define MINI -1

long long int Answer;
int A[100001], B[100001], a_max, N, k, L, ans;
bool visit[100001];

void dfs(int count, int max_f)
{
    //cout << count << " " << max_f << " " << ans << endl;
    if (count == N) 
    {
        ans = max(max_f, ans);
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            k = abs(A[i] - B[count]);
            if (k <= L)
            {
                if (max_f < k)
                    max_f = k;
                visit[i] = true;
                dfs(count + 1, max_f);
                visit[i] = false;
            }
        }
    }
    return ;
}

int main(int argc, char** argv)
{
	int T, test_case;

	//freopen(argv[1], "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = -1;
        cin >> N >> L;

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        sort(A, A + N);
        sort(B, B + N);
        
        ans = 0;
        dfs(0, MINI);
        Answer = ans;

        a_max = MINI;
        for (int i = 0; i < N; i++)
        {
            k = abs(A[i] - B[i]);
            if (k > a_max)
                a_max = k;
        }
        if (a_max > L)
            Answer = -1;
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}