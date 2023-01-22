#include <cstdlib>
#include <iostream>
using namespace std;

long long _max(long long x, long long y) {
    return x > y ? x : y;
}

long long calIC(const long long& n, const long long& b, const char& c)
{
    switch (c)
    {
        case '*': return n * b;
        case '+': return n + b;
        case '-': return n - b;
    }
    return 0;
}

long long calCC(const char& a, const char& b, const char& c)
{
    long long na = a - '0';
    long long nb = b - '0';
    return calIC(na, nb, c);
}

long long solve(const string& s, int i, long long val)
{
    if (i >= s.length()) return val;
    if (i + 1 == s.length()) return calIC(val, s[i] - '0', s[i - 1]);
    
    long long a = solve(s, i + 2, calIC(val, s[i] - '0', s[i - 1]));
    long long b = solve(s, i + 4, calIC(val, calCC(s[i], s[i + 2], s[i + 1]), s[i - 1]));
    return _max(a,b);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    s = '+' + s;
    cout << solve(s, 1, 0) << '\n';
    return 0;
}
