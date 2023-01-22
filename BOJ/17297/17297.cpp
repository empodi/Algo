#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;

string solve(int M)
{
    char c = ' ';
    string tmp = "";
    string second = "Messi Gimossi";
    
    ll A[100] = {0,};
    A[1] = 5;
    A[2] = 13;
    int i = 3;
    for (;;i++)
    {
        A[i] = A[i - 1] + A[i - 2] + 1;
        if (A[i] > M) break;
    }
    
    while (M > 13)
    {
        ll pre = A[i - 1] + 1;
        if (M == pre)
        {
            return "Messi Messi Gimossi";
        }
        else if (M < pre) i--;
        else
        {
            M -= pre;
            i -= 2;
        }
    }
    c = second[M - 1];
    if (c == ' ') return "Messi Messi Gimossi";
    else return tmp + c;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M;
    cin >> M;
    cout << solve(M) << '\n';
    
    return 0;
}
