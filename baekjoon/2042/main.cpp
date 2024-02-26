#include <iostream> // sol 676ms

using namespace std;
long long int seq[4000000];
long long int number[1000000];

long long int make_heap(int start, int end, int index)
{
    if (start == end)
    {
        seq[index] = number[start];
        return (number[start]);
    }

    int mid = (start + end) / 2;
    seq[index] = make_heap(start, mid, index * 2) + make_heap(mid + 1, end, index * 2 + 1);
    return (seq[index]);
}

void change_num(int start, int end, int index, int b, long long int diff)
{
    //if (start > b || end < b)
    //    return ;    
    seq[index] += diff;
    if (start == end)
        return ;
    int mid = (start + end) / 2;  
    if (mid >= b)
        change_num(start, mid, index * 2, b, diff);
    else
        change_num(mid + 1, end, index * 2 + 1, b, diff);
}

long long int print_sum(int start, int end, int index, int from, int to)
{
    if (start > to || end < from)
        return (0);
    if (start >= from && end <= to) return (seq[index]);
    int mid = (start + end) / 2;
    return (print_sum(start, mid, index * 2, from, to) + print_sum(mid + 1, end, index * 2 + 1, from, to));
}

int main(void)
{
    long long int c, diff;
    int a, b, iter, N, M, K;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        cin >> number[i];
    make_heap(0, N - 1, 1);
    iter = M + K;
    for (int i = 0; i < iter; i++)
    {   
        cin >> a >> b >> c;
        if (a == 1)
        {
            diff = c - number[b - 1];
            number[b - 1] = c;
            change_num(0, N - 1, 1, b - 1, diff);
        }
        else if (a == 2)
            cout << print_sum(0, N - 1, 1, b - 1, c - 1) << endl;
    }
}