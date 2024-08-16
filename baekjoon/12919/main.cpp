// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// string a, b;
// int b_size;

// bool dfs(string temp, int length)
// {
//     if (temp == b)
//         return true;
//     if (length >= b_size)
//         return false;
//     if (dfs(temp + 'A', length + 1))
//         return true;
//     temp += 'B';
//     reverse(temp.begin(), temp.end());                    
//     if (dfs(temp, length + 1))
//         return true;
//     return false;
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> a >> b;
//     b_size = b.length();

//     if (dfs(a, a.length()))
//         cout << "1";
//     else
//         cout << "0";
// }


// 미완
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string a, b, temp, count_first = 0, count_second = 0;
    bool check = false;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    temp = a;
    reverse(temp.begin(), temp.end());
    size_t index = b.find(a);
    size_t ind = b.find(temp);
    if (index != string::npos)
    {
        for (int i = 0; i < index; i++)
        {
            if (b[i] == 'B')
                count_first += 1;
        }
        for (int i = index + a.length(); i < b.length(); i++)
        {
            if (b[i] == 'B')
                count_second += 1;
        }
        if ()
    }

}