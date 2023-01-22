#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void change(string& a, const int& pos, const int& N)
{
    for (int i = pos - 1; i <= pos + 1; i++)
    {
        if (i < 0 || i >= N) continue;
        if (a[i] == '0') a[i] = '1';
        else a[i] = '0';
    }
}

int firstSolve(string& a, const string& target, const int& N)    // 첫 버튼 안 누른 경우
{
    int ret = 0;
    for (int i = 1; i < N; i++)
    {
        if (a[i - 1] != target[i - 1]) 
        {
            change(a, i, N);
            ret++;
        }
        if (a == target) return ret;
    }
    return -1;
}

int secondSolve(string& a, string& target, const int& N)    // 첫 버튼 누른 경우
{
    int ret = 1;
    change(a, 0, N);
    for (int i = 1; i < N; i++)
    {
        if (a[i - 1] != target[i - 1]) 
        {
            change(a, i, N);
            ret++;
        }
        if (a == target) return ret;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a, b, target;
    int N;
    cin >> N;
    cin >> a;
    cin >> target;
    b = a;
    int x = firstSolve(a, target, N);
    int y = secondSolve(b, target, N);
    if (x < 0 && y < 0) cout << "-1 \n";
    else if (x < 0 || y < 0) cout << max(x,y) << '\n';
    else cout << min(x,y) << '\n';
    return 0;
}