// 797
// #include <iostream>

// using namespace std;

// int main(void)
// {
// 	for (int j = 0; j < 7; j++) //  7번
// 	{
// 		cout << "DR";
// 		for (int i = 0; i < 14; i++) // 14번
// 			cout << "rFr";
// 		cout << "DL";
// 		for (int i = 0; i < 14; i++) // 14번
// 			cout << "lFl";
// 	}
// 	cout << "D";
// 	for (int i = 0; i < 15; i++) // 15번
// 		cout << "rFr";
// 	for (int i = 0; i < 15; i++) // 15번
// 		cout << "uFu";
// 	for(int i = 0; i < 15; i++) // 15번
// 		cout << "lFl";
// 	for(int i = 0; i < 15; i++) // 15번
// 		cout << "dFd";
// }

// 793
#include <iostream>

using namespace std;

int main(void)
{
	for (int j = 0; j < 7; j++) //  7번
	{
		cout << "DR";
		for (int i = 0; i < 14; i++) // 14번
			cout << "rFr";
		cout << "DL";
		for (int i = 0; i < 14; i++) // 14번
			cout << "lFl";
	}
	for (int i = 0; i < 14; i++) // 14번
		cout << "uFu";
	for (int i = 0; i < 15; i++) // 15번
		cout << "rFr";
	for(int i = 0; i < 15; i++) // 15번
		cout << "dFd";
	for(int i = 0; i < 15; i++) // 15번
		cout << "lFl";
}

