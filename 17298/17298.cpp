#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

int N;
int A[1000001] = {0,};
int B[1000001] = {0,};

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for (int i = N - 1; i >= 0; i--)
    {
        while (!pq.empty() && A[i] >= pq.top()) pq.pop();
        B[i] = pq.empty() ? -1 : pq.top();
        pq.push(A[i]);
    }
    
    for (int i = 0; i < N; i++) cout << B[i] << ' ';
    return 0;
}