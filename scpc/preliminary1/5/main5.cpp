// 128/400
#include <iostream>
#include <vector>
#include  <queue>

using namespace std;

unsigned long long int Answer;

int main(int argc, char** argv)
{
	int T, test_case, n, Q, l, r, front, count;

	freopen(argv[1], "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        unsigned long long int arr[50001];
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        
        cin >> Q;

        cout << "Case #" << test_case+1 << endl;
        for (int i = 1; i <= Q; i++)
        {
            priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int> > qu;
		    Answer = 0;

            cin >> l >> r;
            for (int j = l; j <= r; j++)
            {
                qu.push(arr[j]);
            }
            while (!qu.empty())
            {
                front = qu.top();
                qu.pop();
                count = 1;
                while (!qu.empty() && qu.top() == front)
                {
                    qu.pop();
                    count += 1;
                }
                
                if (front == 1)
                    continue;
                else 
                {
                    count = count / front;
                    Answer += count;
                    front = front * front;
                    for (int j = 1; j <= count; j++)
                        qu.push(front);
                }
            }
            cout << Answer << endl;
        }
	}

	return 0; //Your program should return 0 on normal termination.
}