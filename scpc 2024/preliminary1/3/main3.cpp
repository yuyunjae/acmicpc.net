// 200 / 200
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int Answer;
int count;
int dev[2];
vector<int> line[300001];

void find_end(int curr, int pre)
{
    for (int i = 0; i < 2; i++)
    {
        if (line[curr][i] == dev[1]) return ;
        if (line[curr][i] != pre)
        {
            count += 1;
            return find_end(line[curr][i], curr);
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case, N, a, b, j;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	freopen(argv[1], "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        j = 0;
		Answer = 0;
        cin >> N;
        
        for (int i = 0; i <= N; i++)
        {
            cin >> a >> b;
            line[a].push_back(b);
            line[b].push_back(a);
            if (line[a].size() == 3)
                dev[j++]= a;
            if (line[b].size() == 3)
                dev[j++]= b;
        }

        for (int i = 0; i < 3; i++)
        {
            if (dev[1] == line[dev[0]][i])
            {
                line[dev[0]].erase(line[dev[0]].begin() + i);
                break ;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (dev[0] == line[dev[1]][i])
            {
                line[dev[1]].erase(line[dev[1]].begin() + i);
                break ;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            if (dev[1] != line[dev[0]][i])
            {
                count = 1;
                find_end(line[dev[0]][i], dev[0]);
                Answer += ((unsigned long long int)(count + 1) * count) / 2; // 이거 실수로 조질뻔.. 곱하기 전에 ulli로 바꿔줘야함. 이후에 바꾸면 의미 x
            }
        }

        for (int i = 0; i <= N; i++)
            line[i].clear();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}