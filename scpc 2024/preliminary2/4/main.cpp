#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Answer;
int a[50001];

int main(int argc, char** argv)
{
	int T, test_case, n;
    int left, right, check;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        vector<int> mini;
        vector<int> maxi;
        int mini_val = 2147483647, maxi_val = -1;
        
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (mini_val > a[i])
                mini_val = a[i];
            if (maxi_val < a[i])
                maxi_val = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (mini_val == a[i])
                mini.push_back(i);
            if (maxi_val == a[i])
                maxi.push_back(i);
        }
        if (mini.size() + maxi.size() >= n)
        {
            cout << "Case #" << test_case+1 << endl;
            cout << 0 << endl;
            continue;
        }
        if (mini.size() == n/2 || mini.size() == (n + 1)/2)
        {
            left = 1;
            right = n;
            while (a[left] == mini_val || a[left] == maxi_val)
                left++;
            while (a[right] == mini_val || a[right] == maxi_val)
                right--;
            check = 0;
            for (auto i : maxi)
            {
                if (i >= left - 1 && i <= right + 1)
                {
                    check = 1;
                    break ;
                }
            }
            if (right - left + 1 <= n/2 && check)
            {
                cout << "Case #" << test_case+1 << endl;
                cout << 1 << endl;
                cout << "2 ";
                if (left > 1 && a[left - 1] == maxi_val)
                    cout << left - 1 << " " << right << endl;
                else if (right < n && a[right + 1] == maxi_val)
                    cout << left << " " << right + 1 << endl;
                else
                    cout << left << " " << right << endl;
                continue;
            }     
        }
        if (maxi.size() == n/2 || maxi.size() == (n + 1)/2)
        {
            left = 1;
            right = n;
            while (a[left] == mini_val || a[left] == maxi_val)
                left++;
            while (a[right] == mini_val || a[right] == maxi_val)
                right--;
            check = 0;
            for (auto i : mini)
            {
                if (i >= left - 1 && i <= right + 1)
                {
                    check = 1;
                    break ;
                }
            }
            if (right - left + 1 <= n/2 && check)
            {
                cout << "Case #" << test_case+1 << endl;
                cout << 1 << endl;
                cout << "1 ";
                if (left > 1 && a[left - 1] == mini_val)
                    cout << left - 1 << " " << right << endl;
                else if (right < n && a[right + 1] == mini_val)
                    cout << left << " " << right + 1 << endl;
                else
                    cout << left << " " << right << endl;
                continue;
            }     
        }
        else
        {
            cout << "Case #" << test_case+1 << endl;
            cout << 2 << endl;
            if (mini[0] > maxi[0])
            {
                if (mini[0] > n/2)
                {
                    cout << "2 1 " << n/2 << endl;
                    cout << "1 " << (n + 1)/2 << " " << n << endl;
                }
                else 
                {
                    cout << "1 " << n/2 << " " << n << endl;
                    cout << "2 1 " << n/2 << endl;
                }
            }
            else
            {
                if (maxi[0] > n/2)
                {
                    cout << "1 1 " << n/2 << endl;
                    cout << "2 " << (n + 1)/2 << " " << n << endl;
                }
                else 
                {
                    cout << "2 " << n/2 << " " << n << endl;
                    cout << "1 1 " << n/2 << endl;
                }
            }
        }
	}

	return 0;
}