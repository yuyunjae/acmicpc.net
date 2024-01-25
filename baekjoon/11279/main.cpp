#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> p_queue;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int x;

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
