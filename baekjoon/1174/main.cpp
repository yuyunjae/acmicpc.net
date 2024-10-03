#include <iostream>

using namespace std;

long long number[500000];

int main(void)
{
    int N, index = 1;
    long long num;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < 10; i++)
        number[index++] = i;
    for (int j = 1; j < 500000; j++)
    {
        num = number[j];
        if (num == 987654321)
        {
            number[index] = num * 10 + 0;
            break ;
        }
        for (int i = 0; i < 10; i++)
        {
            if (num % 10 > i)
                number[index++] = num * 10 + i;
            else
                break ;
        }
    }
    if (index < N)
        cout << -1;
    else
        cout << number[N];
}