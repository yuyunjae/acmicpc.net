#include <iostream>

using namespace std;

bool composite_number[4000001]; //합성수

void left_move(int *left)
{
    while (composite_number[*left])
        (*left)++;
}

int main(void)
{
    int N, left = 2, sum = 0, ans = 0;

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> N;
    if (N >= 2)
    {
        for (int i = 4; i <= N; i += 2)
            composite_number[i] = true;
    }
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!composite_number[i])
        {
            for (int j = i * 2; j <= N; j += i)
                composite_number[j] = true;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (!composite_number[i])
        {
            sum += i;
            while (sum > N)
            {
                sum -= left;
                left += 1;
                left_move(&left);
            }
            if (sum == N)
                ans += 1;
        }
    }
    cout << ans;
}