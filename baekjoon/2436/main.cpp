// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> factor;

// int main(void)
// {
// 	int A, B, sum = 2147483647, a, b, min_num, max_num, ans[2] = {-1, -1};
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> A >> B;
// 	if (A == B)
// 	{
// 		cout << A << " " << B;
// 		return (0);
// 	}
// 	for (int i = 1; i <= B; i++)
// 	{
// 		if (B % i == 0)
// 			factor.push_back(i);
// 	}
// 	for (int i = 0; i < factor.size(); i++)
// 	{
// 		for (int j = i + 1; j < factor.size(); j++)
// 		{
// 			if (factor[i] % A == 0 && factor[j] % A == 0 && factor[i] / A * factor[j] == B && factor[j] / A * factor[i] == B)
// 			{
// 				//cout << factor[i] << ": " << factor[j] << endl;
// 				a = factor[i] / A;
// 				b = factor[j] / A;
// 				if (a > b)
// 				{
// 					min_num = b;
// 					max_num = a;
// 				}
// 				else
// 				{
// 					min_num = a;
// 					max_num = b;
// 				}
// 				bool check = true;
// 				for (int k = 2; k <= min_num; k++)
// 				{
// 					if (!(min_num % k))
// 					{
// 						if (!(max_num % k))
// 						{
// 							check = false;
// 							break ;
// 						}
// 						min_num = min_num / k;
// 						k--;
// 					}
// 				}
// 				if (check && sum > factor[i] + factor[j])
// 				{
// 					sum = A * factor[i] + factor[j];
// 					ans[0] = factor[i];
// 					ans[1] = factor[j];
// 					//cout << ans[0] << " " << ans[1] << endl;
// 				}
// 			}
// 		}
// 	}
// 	cout << ans[0] << " " << ans[1];
// }


// 다른 분의 풀이를 참고해서 짠 코드.. 최대 공약수인 gcd는 재귀를 통해 빠르게 구할 수 있다는 것을 잊고 있었는데, 덕분에 다시 기억할 수 있었다.
// 임의의 숫자 a, b의 최대공약수를 A, 최소공배수를 B라고 할 때, B = A * (a / A) * (b / A)가 성립함을 알고 있다면((a / A)와 (b / A)는 서로수이어야 하므로), 쉽게 작성할 수 있는... 코드였다.
// a < b이고 a + b가 최소인 경우를 찾아야하는데, 기본적으로 root(B/A)까지 반복하게 하면, a = i; b < (B/A) / i;로 둔다면, 위의 조건과 a<b를 모두 만족하는 경우가 된다.
// 게다가 a와 b가 비슷해질수록 a + b는 작아지므로, 따로 조건문 필요없이 마지막으로 덮어씌워진 경우를 출력하면 끝.
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)	return (a);
	return gcd(b, a % b);
}

int main(void)
{
	int A, B, a, b, ans[2] = {-1, -1};
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	int count = B / A;
	for (int i = 1; i * i <= count; i++)
	{
		if (count % i == 0)
		{
			a = i;
			b = count / i;
			if (gcd(a, b) == 1)
			{
				ans[0] = A * a;
				ans[1] = A * b;
			}
		}
	}
	cout << ans[0] << " " << ans[1];
}
