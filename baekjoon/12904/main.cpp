// 12919 A와 B 2와 같은 방식으로 해결 a->b가 아닌 b->a를 통해 공간과 시간을 절약할 수 있다.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b, fake;
int a_size;

bool dfs(string temp, int length)
{
    if (temp == a)
        return true;
    if (length <= a_size)
        return false;
    fake = temp.substr(0, length - 1);
    if (temp[length - 1] == 'A')
    {
        if (dfs(fake, length - 1))
            return true;
    }
    if (temp[length - 1] == 'B')
    {
        reverse(fake.begin(), fake.end());
        if (dfs(fake, length - 1))
            return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    a_size = a.length();

    if (dfs(b, b.length()))
        cout << "1";
    else
        cout << "0";
}