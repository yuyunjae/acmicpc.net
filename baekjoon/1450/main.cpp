#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int obj[50];

int main(void) // 미완
{
    int N, C, ans = 1, sum = 0, left = 0, right = 0, val;

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> obj[i];
    sort(obj, obj + N);
    while (right < N && left <= right)
    {
        if (sum + obj[right] <= C)
        {
            sum += obj[right];
            if (left == right) ans += 1;
            else
            {
                val = 1;
                for (int i = 0; i < right - left; i++)
                    val *= 2;
                ans += val;
            }
            right += 1;
        }
        else
        {
            sum -= obj[left];
            left++;
        }
    }
    cout << ans;
}