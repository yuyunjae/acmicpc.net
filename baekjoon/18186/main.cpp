// 100 m/s.. small이랑 똑같은데 B, C 입력 받는 것과, mini * cost를 했을떄 10^6 * 10^6 > INTMAX인것을 간과하여 너무 여러번 틀렸다. 나머지는 같은 듯..
#include <iostream>

using namespace std;

int main(void)
{
    int N, B, C, noodle[1000002], mini, cost2, cost3;
    unsigned long long int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> B >> C;
    for (int i = 0; i < N; i++)
        cin >> noodle[i];
    if (B <= C)
    {
        for (int i = 0; i < N; i++)
            ans += (unsigned long long int)B * noodle[i];
    }
    else
    {
        cost2 = B + C;
        cost3 = B + 2 * C;
        noodle[N] = 0;
        noodle[N + 1] = 0;
        for (int i = 0; i < N; i++)
        {
            while (noodle[i])
            {
                mini = noodle[i];
                if (noodle[i + 1])
                {
                    mini = min(noodle[i], noodle[i + 1]);
                    if (noodle[i + 2])
                    {
                        if (noodle[i] >= noodle[i + 1] || noodle[i + 1] <= noodle[i + 2])
                        {
                            mini = min(mini, noodle[i + 2]);
                            ans += (unsigned long long int)mini * cost3;
                            noodle[i + 2] -= mini;
                        }
                        else
                        {
                            mini = noodle[i + 1] - noodle[i + 2];
                            mini = min(mini, noodle[i]);
                            ans += (unsigned long long int)mini * cost2;
                        }
                    }
                    else
                        ans += (unsigned long long int)mini * cost2;
                    noodle[i + 1] -= mini;
                }
                else
                    ans += (unsigned long long int)mini * B;
                noodle[i] -= mini;
            }
        }
    }
    
    cout << ans;
}

// #include <iostream>

// using namespace std;

// int main(void)
// {
//     int B = 1000000;
//     int C = 1000000;

//     unsigned long long int A;
//     A = (unsigned long long int)B * C;
//     cout << A;
// }