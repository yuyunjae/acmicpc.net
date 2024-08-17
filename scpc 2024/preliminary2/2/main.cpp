#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

unsigned long long int Answer;
// int check[100001]; // size count
// unsigned long long int point[100001];
// unsigned long long int val[100001]; // value
unsigned long long int w[100001];
vector<unsigned long long int> a;

int main(int argc, char** argv)
{
	int T, test_case, N, Q;
    unsigned long long int num, before;
    pair<unsigned long long int, int> p;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
    freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
        int index = 1;
        unsigned long long int before = 0;
        set<int> se;
        priority_queue<pair<unsigned long long int, int>, vector<pair<unsigned long long int, int> >, greater<pair<unsigned long long int, int> > > pq;

		Answer = 0;
        cin >> N >> Q;
        for  (int i = 1; i <= N; i++)
        {
            cin >> w[i];
            pq.emplace(w[i], i);
            se.emplace(i);
        }
        before = 0;
        if (N <= 1000 && Q <= 1000)
        {
            while (!pq.empty())
            { 
                p = pq.top();
                for (int i = 0; i <p.first - before; i++)
                {
                    for(auto j : se)
                        a.push_back(j); // a가 너무 커져서 터지는 듯..
                }
                pq.pop();
                se.erase(p.second);
                while(!pq.empty() && p.first == pq.top().first)
                {
                    pq.pop();
                    se.erase(p.second);
                }
                //cout << " " << p.first << " " << p.second << " " << pq.size() << " " << a.size() << " " << endl;
                before = p.first;
            }
        }
        // for (auto i : a)
        //     cout << i << endl;

        for (int i = 0; i < Q; i++)
        {
            cin >> num;
            if (a.size() > num - 1)
                Answer += a[num - 1];
            // cout << num << " " << a[num - 1] << endl;
        }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
        a.clear();
	}

	return 0;
}