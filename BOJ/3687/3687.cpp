#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<string> dict[10];
string minStr[101], maxStr[101];

void setDict()
{
    dict[2].push_back("1");
    dict[3].push_back("7");
    dict[4].push_back("4");
    dict[5] = {"2","3","5"};
    dict[6] = {"0","6","9"};
    dict[7].push_back("8");
}

string getMin(const string& a, const string& b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i]) continue;
            else if (a[i] < b[i]) return a;
            else return b;
        }
    }
    if (a.length() < b.length()) return a;
    return b;
}

void setMin()
{
    for (int i = 2; i < 8; i++) minStr[i] = dict[i][0] != "0" ? dict[i][0] : dict[i][1];
    for (int i = 8; i < 101; i++)
    {
        string res = "";
        for (int i = 0; i < 100; i++) res += "9";
        for (int j = 2; j < 8; j++)
        {
            if (i - j < 2) continue;
            string a = minStr[i - j] + dict[j][0];
            res = getMin(res, a);
        }
        minStr[i] = res;
    }
}

void setMax()
{
    maxStr[2] = dict[2].back();
    maxStr[3] = dict[3].back();
    for (int i = 4; i < 101; i++)
        maxStr[i] = maxStr[i - 2] + "1";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    setDict();
    setMin();
    setMax();
    while (N--)
    {
        int n; 
        cin >> n;
        cout << minStr[n] << ' ' << maxStr[n] << '\n';   
    }
    return 0;
}