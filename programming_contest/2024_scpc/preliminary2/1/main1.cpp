// 60/200
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXI 1e17

unsigned long long int Answer, dp[300001];

int main(int argc, char** argv)
{
	int T, test_case, N, S, E, end, temp, v_size;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
        vector<int> point;
		Answer = 0;
		cin >> N >> S >> E;
        
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            if (temp)
                point.push_back(i);
        }
        v_size = point.size();
        
        if (v_size)
        Answer = MAXI;

        //cout << N << " " << S << " " << E << " " << Answer << " " << v_size << endl;
        for (int i = 0; i < v_size; i++)
        {
            dp[i] = MAXI;
            end = v_size;
            while (end--)
            {
                if (end < i)
                    break ;
                dp[i] = min(dp[i], ((unsigned long long int)(point[end] - point[i] - end + i)) * S + ((unsigned long long int)(i + v_size -1 - end)) * E);
            }
            if (dp[i] < Answer)
                Answer = dp[i];
        }
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}