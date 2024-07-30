// 63/300
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

double Answer[100000];
int point[100000][2];
int police[100000][2];
double prob[100000];

int main(int argc, char** argv)
{
	int T, test_case, n, m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
        cin >> n;
        for (int i = 0; i< n; i++)
            cin >> point[i][0] >> point[i][1];
        for (int i = 0; i< n; i++)
        {
            cin >> prob[i];
            //cout << prob[i] << "prob\n";
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            Answer[i] = 0;
            cin >> police[i][0] >> police[i][1];
            for (int j = 0; j < n; j++)
            {
                Answer[i] += prob[j] * (abs(police[i][0] - point[j][0]) + abs(police[i][1] - point[j][1]));
                //cout << Answer[i] << " " << a << endl;
            }
        }
        

		cout << "Case #" << test_case+1 << endl;
        for (int i = 0; i < m; i++)
		    cout << Answer[i] << endl;
	}

	return 0;
}