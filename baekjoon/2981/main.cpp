#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int num[100];
int	diff[99];
vector<int> divi;
set<int> ans;
set<int> temp;

int gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int main(void)
{
	int N, remain = 0;
	bool flag;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);
	diff[0] = num[1] - num[0];
	remain = diff[0];
	for (int i = 1; i < N - 1; i++)
	{
		diff[i] = num[i + 1] - num[i];
		remain = gcd(remain, diff[i]);
	}
	// cout << "remain" << remain << endl;
	for (int i = 2; i <= remain; i++)
	{
		while (remain % i == 0)
		{
			remain /= i;
			divi.push_back(i);
			// cout << i << endl;
		}
	}
	for (auto i : divi)
	{
		for (auto j : ans)
			temp.insert(i * j);
		for (auto j : temp)
			ans.insert(j);
		if (ans.find(i) == ans.end())
			ans.insert(i);
		temp.clear();
	}
	for (auto i : ans)
		cout << i << " ";
}


/*
다른분의 코드... 약수를 구하는데, 너무 바보 같이 생각했었나보다.. 그냥 너무 간단하게 푸셨다.. 그리고 최대공약수, 최대 공배수 공부좀 해야할듯....
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, gcd;
int x;
vector<int> v, ans;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	cin >> N;

	// 수들을 입력받고 정렬
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	gcd = v[1] - v[0];
	for (int i = 2; i < N; i++) gcd = GCD(gcd, v[i] - v[i - 1]);

	for (int i = 2; i * i <= gcd; i++)
		if (gcd % i == 0)
		{
			ans.push_back(i);
			ans.push_back(gcd / i);
		}

	ans.push_back(gcd);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 중복된 원소들 제거

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

}
*/
