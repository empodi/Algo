#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
inline int MAX(int a, int b){return a>b?a:b;}
inline bool check(char c){return (c=='a'||c=='n'||c=='t'||c=='i'||c=='c');}

int n, k;
vector<string> words;
vector<char> alpha;

void get_input() {
    cin >> n >> k;
    vector<bool> chk(26, false);
    for (int i = 0; i < n; i++) 
    {
        string str;
        cin >> str;
        words.push_back(str);
        for (char c:str) 
        {
            if (check(c)) continue;
            if (chk[c]) continue;
            chk[c] = true;
            alpha.push_back(c);
        }
    }
    //for (auto& c : alpha) cout << c << " "; cout << endl;
}

int readable(vector<char>& v) {
    int cnt = 0;
    vector<bool> chk(26, false);
    for (auto& c : v) chk[c - 'a'] = true;
    for (auto& word : words)
    {   
        bool flag = true;
        for (auto& c : word)
        {
            if (check(c)) continue;
            if (chk[c - 'a'] == false) 
            {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    return cnt;
}

void solve(vector<char>& v, int pos, int limit, int& answer) {
    if (limit == v.size() || alpha.size() == v.size())
    {
        answer = MAX(answer, readable(v));
        return;
    }
    for (int i = pos; i < alpha.size(); i++)
    {
        v.push_back(alpha[i]);
        solve(v, i + 1, limit, answer);
        v.pop_back();
    }
}

int get_answer() {
    if (k < 5) return 0;
    k -= 5;
    vector<char> v;
    int answer = 0;
    solve(v, 0, k, answer);
    return answer;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
    get_input();
    cout << get_answer() << "\n";
   
    return 0;
}

