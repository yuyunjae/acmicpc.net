// n ^ 3으로 계속 시간초과가 발생했다. 가지치기만 좀 잘하면 통과 할 줄 알았는데 어림도 없었다. 결국 생각이 나지 않아서 다른 코드를 통해 아이디어를 얻어 해결했다.
// upper_bound, lower_bound를 처음 사용해보는데, 너무 좋은 것 같다. 그동안 이진탐색을 직접 구현해서 사용했는데, 알고리즘 문제를 풀 때는 그냥 해당 함수들을 사용해도 될 것 같다.
// 1928 m/s O((n^2)log(n))

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	unsigned long long int ans = 0;
	int student[10001], n, sum;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> student[i];
	sort(student, student + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = student[i] + student[j];
			ans += upper_bound(student + j + 1, student + n, -sum) - lower_bound(student + j + 1, student + n, -sum);
			//cout << student[i] << " " << student[j] << " " << ans << endl;
		}
	}
	cout << ans;
}


/*

// 다른 분의 코드
// 68 m/s O(n^2) dp를 이용해 짧고 아름답게 푸셨다... 이런 발상은 정말 배워야 할듯..
#include<bits/stdc++.h>
using namespace std;
int N;
int m[11111];
int dp[33333];
long long cnt;
int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        x += 10000;
        dp[x]++;
        m[i] = x;
    }
    for(int i=0;i<N;i++) {
        int x = m[i];
        dp[x]--;
        for(int j=0;j<i;j++) {
            int y = m[j];
            if(x + y <= 30000)
                cnt += dp[30000 - x - y];
        }
    }
    cout<<cnt<<'\n';
}

*/
