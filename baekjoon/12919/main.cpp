// a -> b 가 최대 2^49인지라 dfs, bfs로 풀지 못할 것이라 생각했다. 그래서 아래 주석부분처럼 규칙을 찾으려고 했는데, 결국 다 실패..
// 알고 보니 b -> a로 생각하면, b문자열을 보고 하나씩 줄여가면서 전개하면 되는 것이었다. 신기하게 생각보다 결과는 좋다..
// a = BAAA..A와 같이 B 1개 A 25개의 결합이고, b = B..BA어ㅣ 깉이 B 25개 A 1개의 결합이라고 생각해보자.
// 이 경우가 내가 생각하기에 최악의 경우인데, 2 ^ 25 정도의 복잡도로 해결가능하다. (a -> b의 최악의 경우의 root배 인듯).. 
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
    if (temp[length - 1] == 'A')
    {
        fake = temp.substr(0, length - 1);
        if (dfs(fake, length - 1))
            return true;
    }
    if (temp[0] == 'B')
    {
        fake = temp.substr(1);
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


// 규칙을 찾으려했으나 실패.. ㅎㅎ...
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main(void)
// {
//     string a, b, temp;
//     int count_first = 0, count_second = 0;
//     bool check = false;
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     cin >> a >> b;
//     size_t index = b.find(a);

//     while (index != string::npos)
//     {
//         count_first = 0;
//         count_second = 0;
//         for (int i = 0; i < index; i++)
//         {
//             if (b[i] == 'B')
//                 count_first += 1;
//         }
//         for (int i = index + a.length(); i < b.length(); i++)
//         {
//             if (b[i] == 'B')
//                 count_second += 1;
//         }
//         if ((count_second == count_first || count_second == count_first - 1) && ((count_first < 1 && index == 0) || b[0] == 'B'))
//         {
//             check = true;
//             break ;
//         }
//         index = b.find(a, index + 1);
//     }
//     temp = a;
//     reverse(temp.begin(), temp.end());
//     size_t ind = b.find(temp);

//     if (!check)
//     {
//         while (ind != string::npos)
//         {
//             count_first = 0;
//             count_second = 0;   
//             for (int i = 0; i < ind; i++)
//             {
//                 if (b[i] == 'B')
//                     count_first += 1;
//             }
//             for (int i = ind + temp.length(); i < b.length(); i++)
//             {
//                 if (b[i] == 'B')
//                     count_second += 1;
//             }
//             if ((count_second == count_first || count_second == count_first - 1) && count_first > 0 && b[0] == 'B')
//             {
//                 check = true;
//                 break ;
//             }
//             ind = b.find(temp, ind + 1);
//         }
//     }
//     if (check)
//         cout << "1";
//     else
//         cout << "0";
// }