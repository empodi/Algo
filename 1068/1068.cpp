#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int N, root, target;
int answer = 0;
vector<int> graph[55];

void countLeaf(int cur)
{
    if (cur == target) return;
    if (graph[cur].empty())
    {
        answer++;
        return;
    }
    int cnt = 0;
    for (auto elem : graph[cur]) 
    {
        if (elem != target)
        {
            countLeaf(elem);
            cnt++;
        }
    }
    if (cnt == 0) answer++;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (n == -1) root = i;
        else graph[n].push_back(i); // n is parent
    }
    
    cin >> target;
    graph[target].clear();
    
    countLeaf(root);
    cout << answer << '\n';
    return 0;
}