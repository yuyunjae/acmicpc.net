// 128 / 400
#include <iostream>
#include <map>

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
            map<unsigned long long int, int> m;
		    Answer = 0;

            cin >> l >> r;
            for (int j = l; j <= r; j++)
            {
                auto a = m.find(arr[j]);
                if (a != m.end())
                    a->second += 1;
                else
                    m.insert({arr[j], 1});
            }
            for (auto iter = m.begin(); iter != m.end(); iter++)
            {
                if (iter->first == 1)
                    continue;
                
                count = iter->second / iter->first;
                if (count)
                {
                    Answer += count;
                    front = iter->first * iter->first;
                    auto a = m.find(front);
                    if (a != m.end())
                        a->second += count;
                    else
                        m.insert({front, count});
                }
            }
            cout << Answer << endl;
        }
	}

	return 0; //Your program should return 0 on normal termination.
}