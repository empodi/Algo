#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#define co(a) (cout << a << '\n')
using namespace std;

/*
0 1 2
3 4 5
6 7 8
*/

string getIndices(int n)
{
    if (n == 0) return "13";
    else if (n == 1) return "024";
    else if (n == 2) return "15";
    else if (n == 3) return "046";
    else if (n == 4) return "1357";
    else if (n == 5) return "248";
    else if (n == 6) return "37";
    else if (n == 7) return "468";
    return "57"; // n == 8
}

int solve(const string& s)
{
    queue<pair<string,int>> q;
    set<string> _set;
    
    q.push({s, 0});
    _set.insert(s);
    
    while (!q.empty())
    {
        string ss = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (ss == "123456780") return cnt;
        
        int zeroIdx = 0;
        for (; zeroIdx < 9; zeroIdx++) 
            if (ss[zeroIdx] == '0') break;
        
        string indices = getIndices(zeroIdx);
        
        for (auto& e : indices)
        {
            swap(ss[zeroIdx], ss[e - '0']);
            if (_set.find(ss) == _set.end())
            {
                q.push({ss, cnt + 1});
                _set.insert(ss);
            }
            swap(ss[zeroIdx], ss[e - '0']);
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            s.push_back(c);
        }
    }
    co(solve(s));
    return 0;
}