// unordered set으로 필요한 알파벳들만 사용하는 최적화를 하려고 했는데, 오히려 그게 시간초과가 발생했다..
// 결국 문자열이 길고 복잡해지면, 사실상 거의 대부분의 알파벳이 나오기 때문에, 탑색에서 차이가 없고, 
//for (int i = index; i < 26; i++) 이부분과 초기에 필요한 알파벳을 걸러내는 과정에서 시간 소모가 큰 것 같다.
//240 ms
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vec;
bool alpha[26]; // 'a' = 97 ~ 'z' = 122
int ans;
int N, K;

void dfs(int depth, int index)
{
    int val{};
    if (K == depth)
    {
        for (auto i : vec)
        {
            bool check = false;
            for (auto j : i)
            {
                if (!alpha[j - 'a'])
                    check = true;
            }
            if (!check)
            val += 1;
        }

        if (ans < val)
            ans = val;

        if(ans == N){
            cout << N << '\n';
            exit(0);
        }
    }

    for (int i = index; i < 26; i++)
    {
        if (!alpha[i])
        {
            alpha[i] = true;
            dfs(depth + 1, i);
            alpha[i] = false;
        }
    }
}

int main(void)
{
    string str;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        vec.push_back(str.substr(4, str.length() - 8));
    }
    if (K < 5)
    {
        cout << 0;
        return (0);
    }
    K -= 5;
    alpha[0] = true, alpha['n' - 97] = true, alpha['t' - 97] = true, alpha['i' - 97] = true, alpha['c' - 97] = true;
    dfs(0, 1);
    cout << ans;
}

/* 24 ms
10배 빠른 bitmask //https://nanyoungkim.tistory.com/173 -> 다른 분의 블로그.,.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int checked;
int word[50];   //N 최대 50개
int N, K;
 
int maxi = 0;
 
void DFS(int toPick, int start, int checked){    //증복조합
    
    if(toPick==0){  //배울 알파벳 골랐으면
        
        //그 알파벳들로 N개 단어 중 몇개 읽을 수 있는지 카운트해서 최대값 찾기
        int cnt = 0;
        for(int i = 0; i<N ;i++){
            if((word[i] & checked) == word[i]) cnt++;
        }
        if(maxi < cnt) maxi = cnt;
        return;
    }
 
    for(int i = start; i<26; i++){
        if((checked & (1<<i)) == 0){   //방문 안 한 경우에만
            checked |= (1<<i);
            DFS(toPick-1, i, checked);
            checked &= ~(1<<i); // 아름답다...
        }
        
    }
}
 
int main(){
    
    cin >> N >> K;
    
    string str;
    for(int i = 0; i<N; i++){
        cin >> str;
        
        int num = 0;
        for(int j = 0; j<str.length(); j++){
            num |= 1 << (str[j] - 'a');
        }
        word[i] = num;
    }
    
    if(K<5) cout << 0;  //anta ~ tica 읽으려면 최소 a,n,t,i,c 5개 이상은 알고 있어야함
    else if (K==26) cout << N;
    else{
        
        //a, n, t, i, c 를 이미 알고 있음을 초기화.
        checked |= 1 << ('a'-'a');
        checked |= 1 << ('n'-'a');
        checked |= 1 << ('t'-'a');
        checked |= 1 << ('i'-'a');
        checked |= 1 << ('c'-'a');
        
        DFS(K-5, 0, checked);
        cout << maxi;
    }
 
    return 0;
}
*/