#include <iostream>
#include <vector>

using namespace std;

typedef struct s_dice{
    int num[6];
} dice;

vector<dice> dices;

int opposite[6] = {5, 3, 4, 1, 2, 0};

int max_dice(dice &d, int i, int j)
{
    int maxi = 0;

    for (int k = 0; k < 6; k++)
    {
        if ((k != i && k != j) && maxi < d.num[k])
            maxi = d.num[k];
    }
    return maxi;
}

int main(void)
{
    int n, answer_max = 0, answer = 0, front_val;
    dice temp;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            cin >> temp.num[j];
        dices.push_back(temp);
    } 

    for (int i = 0; i < 6; i++)
    {
        answer = max_dice(dices[0], i, opposite[i]);
        // cout << i << " " << answer << endl;
        front_val = dices[0].num[opposite[i]];
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (dices[j].num[k] == front_val)
                {
                    answer += max_dice(dices[j], k, opposite[k]);
                    // cout << k << ":" << opposite[k] << " " << answer << "  "  << dices[j].num[opposite[k]] << endl;
                    front_val = dices[j].num[opposite[k]];
                    break ;
                }
            }
        }
        if (answer_max < answer)
            answer_max = answer;
    }
    cout << answer_max;
}