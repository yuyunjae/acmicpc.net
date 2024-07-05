/// 100 / 100
#include <iostream>
#include <string>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, N;
    string str;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	//freopen(argv[1], "r", stdin); // 이걸 제출 전에 주석처리..하라네.. 그럼 도대체 어캐 읽는 거지 ㅋㅋ
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        
        cin >> N;		
        cin >> str;
        
        for (int i = 0; i < N - 2; i++)
        {
            if (str[i] == 'A')
            {
                if (str[i + 1] == 'A')
                {
                    Answer += 2;
                    continue;
                }
                if (str[i + 2] == 'A')
                    Answer += 1;
            }
        }

        if (str[N - 2] == 'A' && str[N - 1] == 'A')
        {
            Answer += 2;
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}