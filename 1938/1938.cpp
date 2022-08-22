#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#define co(a) (cout << a << '\n')
using namespace std;
typedef pair<int,int> pii;

char map[55][55];
vector<pii> tree;
vector<pii> E;
unordered_map<string ,int> um;
int N;

void get_input() {
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j];
            if (map[i][j] == 'B') tree.push_back({i,j});
            else if (map[i][j] == 'E') E.push_back({i,j});
        }
    }
    sort(tree.begin(), tree.end());
    sort(E.begin(), E.end());
}

string makeString(int a, int b, int c, int d) {
    return to_string(a) + " " + to_string(b) + " " + to_string(c) + " " + to_string(d);
}

bool checkUp(vector<pii>& v) {
    for (auto& c : v)
    {
        if (c.first - 1 < 0 || map[c.first - 1][c.second] == '1') return false;
    }
    return true;
}

bool checkDown(vector<pii>& v) {
    for (auto& c : v)
    {
        if (c.first + 1 >= N || map[c.first + 1][c.second] == '1') return false;
    }
    return true;
}

bool checkRight(vector<pii>& v) {
    for (auto& c : v)
    {
        if (c.second + 1 >= N || map[c.first][c.second + 1] == '1') return false;
    }
    return true;
}

bool checkLeft(vector<pii>& v) {
    for (auto& c : v)
    {
        if (c.second - 1 < 0 || map[c.first][c.second - 1] == '1') return false;
    }
    return true;
}

bool checkRotate(vector<pii>& v) {
    int dir[8][2] = { {1,0},{1,-1},{1,1},{-1,-1},{-1,0},{-1,1},{0,1},{0,-1} };
    for (int k = 0; k < 8; k++)
    {
        int nx = v[1].first + dir[k][0];
        int ny = v[1].second + dir[k][1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == '1') return false;
    }
    return true;
}

vector<pii> RR(vector<pii>& v) {
    vector<pii> ret(2);
    if (v[0].first == v[2].first) // 가로
    {
        ret[0] = { v[1].first - 1, v[1].second };
        ret[1] = { v[1].first + 1, v[1].second };
    }
    else // 세로
    {
        ret[0] = { v[1].first, v[1].second - 1 };
        ret[1] = { v[1].first, v[1].second + 1 };
    }
    return ret;
}

int solve() {
    queue<pair<pair<pii,pii>, int>> q;
    q.push( { { tree[0], tree[2] }, 0 } );
    um[makeString(tree[0].first, tree[0].second, tree[2].first, tree[2].second)] = true;
    
    while (!q.empty())
    {
        vector<pii> v(3);
        v[0] = q.front().first.first;
        v[2] = q.front().first.second;
        v[1] = { (v[0].first + v[2].first) / 2, (v[0].second + v[2].second) / 2 };
        int cnt = q.front().second;
        q.pop();
        
        sort(v.begin(), v.end());
        if (v[0] == E[0] && v[1] == E[1] && v[2] == E[2]) return cnt;
        
        cnt++;
        if (checkUp(v))
        {
            string s = makeString(v[0].first - 1, v[0].second, v[2].first - 1, v[2].second);
            if (um.find(s) == um.end())
            {
                q.push({{{v[0].first-1, v[0].second}, {v[2].first-1, v[2].second}}, cnt });
                um[s] = true;
            }
        }
        if (checkDown(v))
        {
            string s = makeString(v[0].first + 1, v[0].second, v[2].first + 1, v[2].second);
            if (um.find(s) == um.end())
            {
                q.push({{{v[0].first+1, v[0].second}, {v[2].first+1, v[2].second}}, cnt });
                um[s] = true;
            }
        }
        if (checkRight(v))
        {
            string s = makeString(v[0].first, v[0].second + 1, v[2].first, v[2].second + 1);
            if (um.find(s) == um.end())
            {
                q.push({{{v[0].first, v[0].second+1}, {v[2].first, v[2].second+1}}, cnt });
                um[s] = true;
            }
        }
        if (checkLeft(v))
        {
            string s = makeString(v[0].first, v[0].second - 1, v[2].first, v[2].second - 1);
            if (um.find(s) == um.end())
            {
                q.push({{{v[0].first, v[0].second-1}, {v[2].first, v[2].second-1}}, cnt });
                um[s] = true;
            }
        }
        if (checkRotate(v))
        {
            vector<pii> r = RR(v);
            string s = makeString(r[0].first, r[0].second, r[1].first, r[1].second);
            if (um.find(s) == um.end())
            {
                q.push({{{r[0].first, r[0].second}, {r[1].first, r[1].second}}, cnt });
                um[s] = true;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    co(solve());
    return 0;
}
