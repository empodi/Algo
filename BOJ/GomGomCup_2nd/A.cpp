#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, ret = 0; 
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        int n = stoi(s.substr(2,s.length()-2));
        if (n <= 90) ret++;
    }
    cout << ret << '\n';
    return 0;
}