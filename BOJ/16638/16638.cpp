#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int getPriority(const char& c)
{
    if (c == '*') return 3;
    if (c == '+' || c == '-') return 2;
    return 1;
}

string postfix(const string& s)
{
    string ret;
    stack<char> stk;
    for (char c : s)
    {
        if (c >= '0' && c <= '9') ret += c;
        else if (c == '(') stk.push(c);
        else if (c == ')')
        {
            while (!stk.empty())
            {
                char tmp = stk.top();
                stk.pop();
                if (tmp == '(') break;
                ret += tmp;
            }
        }
        else // 연산자
        {
            while (true)
            {
                int newPrt = getPriority(c);
                int stkPrt = stk.empty() ? -1 : getPriority(stk.top());
                if (newPrt <= stkPrt)
                {
                    ret += stk.top();
                    stk.pop();
                }
                else
                {
                    stk.push(c);
                    break;
                }
            }
        }
    }
    while (!stk.empty())
    {
        ret += stk.top();
        stk.pop();
    }
    return ret;
}

string join(vector<char>& v, const int& N)
{
    string ret;
    for (int i = 0; i < N * 2; i++)
        if (v[i] != ' ')
            ret += v[i];
    if (v[N * 2] == ')') ret += ')';
    return ret;
}

int cal(const string& s)
{
    stack<int> stk;
    for (char c : s)
    {
        if (c >= '0' && c <= '9') stk.push(c - '0');
        else
        {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            switch (c)
            {
                case '*': stk.push(a * b); break;
                case '+': stk.push(a + b); break;
                case '-': stk.push(b - a); break;
            }
        }
    }
    return stk.top();
}

void solve(vector<char>& v, int pos, int& ret, const string& s, const int& N)
{
    if (pos > N * 2)
    {
        ret = max(ret, cal(postfix(join(v, N))));
        return;
    }
    solve(v, pos + 4, ret, s, N);
    if (pos <= N * 2 - 6)
    {
        v[pos] = '(';
        v[pos + 6] = ')';
        solve(v, pos + 8, ret, s, N);
        v[pos] = v[pos + 6] = ' ';
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, ret = INT_MIN;
    string s;
    vector<char> v(40, ' ');
    cin >> N;
    cin >> s;
    for (int i = 0; i < s.length(); i++) v[i * 2 + 1] = s[i];
    solve(v, 0, ret, s, N);
    cout << ret << '\n';
    return 0;
}
