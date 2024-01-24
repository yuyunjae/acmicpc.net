#include <iostream>
#include <algorithm>

using namespace std;

int sequence[1000001];

void    binary_push(int *size, int num)
{
    if (*size == 0 || sequence[*size - 1] < num)
    {
        sequence[(*size)++] = num;
        return ;
    }

    int max = *size;
    int right = max - 1, left = 0;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (sequence[mid] > num)
            right = mid - 1;
        else if (sequence[mid] < num)
            left = mid + 1;
        else
            return ;
    }
    sequence[left] = num;
}

int main(void)
{
    int N, num, count = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        binary_push(&count, num);
    }
    cout << count;
}