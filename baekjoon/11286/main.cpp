#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
struct cmp
{
    bool operator()(const T &a, const T &b)
    {
        if (abs(a) == abs(b))
            return (a > b);
        return (abs(a) > abs(b));
    }
};

priority_queue<int, vector<int>, cmp<int> > p_queue;

int main(void)
{
    int N, x;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            if (p_queue.empty())
                cout << "0\n";
            else
            {
                cout << p_queue.top() << '\n';
                p_queue.pop();
            }
        }
        else
            p_queue.push(x);
    }
}