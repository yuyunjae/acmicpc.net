#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

void make_vector(vector<int> &vec, const string &a)
{
    for (auto i : a)
    {
        if (i == 'I')
            vec.push_back(I);
        else if(i == 'V')
            vec.push_back(V);
        else if(i == 'X')
            vec.push_back(X);
        else if(i == 'L')
            vec.push_back(L);
        else if(i == 'C')
            vec.push_back(C);
        else if(i == 'D')
            vec.push_back(D);
        else if(i == 'M')
            vec.push_back(M);
    }
}

int vec_to_val(const vector<int> &vec)
{
    int val{};
    for (int i = 0; i < vec.size(); i++) {
        if (i + 1 < vec.size() && vec[i] < vec[i + 1])
        {
            val += vec[i + 1] - vec[i];
            i++;
        }
        else
            val += vec[i];
        //cout << vec[i] << " ";
    }
    return val;
}

void val_to_str(int val, string &ans)
{
    while (val / M)
    {
        ans += 'M';
        val -= 1000;
    }
    if (val >= 900)
    {
        ans += "CM";
        val -= 900;
    }
    if (val >= 500)
    {
        ans += 'D';
        val -= 500;
    }
    if (val >= 400)
    {
        ans += "CD";
        val -= 400;
    }
    while (val >= 100)
    {
        ans += 'C';
        val -= 100;
    }
    if (val >= 90)
    {
        ans += "XC";
        val -= 90;
    }
    if (val >= 50)
    {
        ans += 'L';
        val -= 50;
    }
    if (val >= 40)
    {
        ans += "XL";
        val -= 40;
    }
    while (val >= 10)
    {
        ans += 'X';
        val -= 10;
    }
    if (val == 9)
    {
        ans += "IX";
        val = 0;
    }
    if (val >= 5)
    {
        ans += "V";
        val -= 5;
    }
    if (val == 4)
    {
        ans += "IV";
        val -= 4;
    }
    while (val--)
        ans += 'I';
}

int main(void)
{
    string a, b;
    vector<int> vec1;
    vector<int> vec2;
    string ans;
    int val1 = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    make_vector(vec1, a);
    make_vector(vec2, b);
    val1 = vec_to_val(vec1);
    val1 += vec_to_val(vec2);
    cout << val1 << '\n';
    val_to_str(val1, ans);
    cout << ans;
}