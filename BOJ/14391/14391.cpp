#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int A[5][5] = {0,};

void get_input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) A[i][j] = s[j] - '0';
    }
}

int getVertical(int row_s, int col, int row_e)
{
    int ret = 0;
    for (int k = row_s; k <= row_e; k++)
        ret = ret * 10 + A[k][col];
    return ret;
}

int getHorizontal(int row, int col_s, int col_e)
{
    int ret = 0;
    for (int k = col_s; k <= col_e; k++)
        ret = ret * 10 + A[row][k];
    return ret;
}

int solve(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2) return 0;
    if (x1 >= N || x2 >= N || y1 >= M || y2 >= M) return 0;
    if (x1 == x2) return getHorizontal(x1, y1, y2);
    if (y1 == y2) return getVertical(x1, y1, x2);

    int ret = 0;
    for (int k = x1; k < x2; k++)
        ret = max(ret, solve(x1, y1, k, y2) + solve(k + 1, y1, x2, y2));
    for (int k = y1; k < y2; k++)
        ret = max(ret, solve(x1, y1, x2, k) + solve(x1, k + 1, x2, y2));
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    cout << solve(0,0,N-1,M-1) << '\n';
    return 0;
}

