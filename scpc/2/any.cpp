
#include <iostream>
#include <random>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    std::random_device rd;

    std::mt19937 gen(rd());

    
    std::uniform_int_distribution<int> dis(0, 15000);

  for (int i = 0; i < 200; i++) {
    std::cout << dis(gen) << " ";
  }

  int count = 300000;
  Answer = ((unsigned long long int)(count + 1) * count) / 2;
  cout << Answer << endl;

  Answer = (unsigned long long int)((count + 1) * count) / 2;
  cout << Answer << endl;
}