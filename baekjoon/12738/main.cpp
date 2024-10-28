// 미완
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int answer;

void find_arr(int value)
{
    int index = lower_bound(vec.begin(), vec.end(), value) - vec.begin();
    if (vec[index] > value)
        vec[index] = value;
}

int main(void)
{
    int N, a;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    vector<int> arr;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    vec.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > vec[answer])
        {
            vec.push_back(arr[i]);
            answer++;
        }
        // else find_arr(i);
    }
    cout << answer;
}