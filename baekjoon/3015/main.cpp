#include <iostream>

using namespace std;

int height[500002];
int people[500002][2];

int main(void)
{
    int N;
    int top_size = 1;
    long long int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> height[i];
    people[0][0] = height[0];
    people[0][1] = 1;
    for (int i = 1; i < N; i++)
    {
        while (top_size > 0)
        {
            if (people[top_size - 1][0] < height[i])
            {
                ans += people[top_size - 1][1];
                //cout << ans << " " << people[top_size - 1][0] << " " << people[top_size - 1][1] << " " << height[i] << " : 1" << endl;
                top_size -= 1;
            }
            else if (people[top_size - 1][0] == height[i])
            {
                ans += people[top_size - 1][1];
                //cout << ans << " " << people[top_size - 1][0] << " " << people[top_size - 1][1] << " " << height[i] << " : 2" << endl;
                people[top_size - 1][1] += 1;
                if (top_size > 1)
                    ans += 1;
                break ;
            }
            else if (people[top_size - 1][0] > height[i])
            {
                ans += 1;
                //cout << ans << " " << people[top_size - 1][0] << " " << people[top_size - 1][1] << " " << height[i] << " : 3" << endl;
                break ;
            }
        }
        if (!top_size || people[top_size - 1][0] != height[i])
        {
            people[top_size][0] = height[i];
            people[top_size++][1] = 1;
        }
    }
    cout << ans;
}

// 다시 생각해보니 굳이 height 배열을 만들지 않고 그냥 for문에서 입력받고 바로바로 비교하면서 처리했으면 500002 * 4byte의 공간을 아낄 수 있었을 듯.
/*
ios::sync_with_stdio(false);
cin.tie(NULL);
입력을 많이 받을 떄는 꼭 사용하자. 속도가 4배는 빨라졌다.
cout.tie(NULL; 도 원래는 같이 썼는데 cout을 많이 사용하지 않아서 그런가, 아니면 cin 쪽에서 동기화를 풀어주면 양쪽에서 모두 풀리는 건지는 모르겠지만 추가해도 속도 변화 x
*/