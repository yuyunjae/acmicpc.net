// 150/150
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long int Answer; // int로 하면 부분 점수만 받게 됨
int thing[300001];

int main(int argc, char** argv)
{
	int T, test_case, count, N;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	//freopen(argv[1], "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> thing[i];
        
        sort(thing, thing + N);
        count = N - 1;

        for (int i = 0; i < N / 4; i++)
        {
            Answer += (thing[count] - thing[i]) * 2;
            count--;
        }
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}