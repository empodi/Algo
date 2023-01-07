#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int N, E = 0, R = 0;
int A[100001][2];

void get_input()
{
    memset(A, -1, sizeof(A));
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, l, r;
        cin >> a >> l >> r;
        A[a][0] = l;
        A[a][1] = r;
        if (l > 0) E++;
        if (r > 0) E++;
    }
}

void goRight(int cur)
{
    if (cur < 0) return;
    R++;
    goRight(A[cur][1]);
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get_input();
    goRight(A[1][1]);
    cout << E * 2 - R << '\n';
    return 0;
}
