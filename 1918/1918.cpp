#include <cstdlib>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool pushToResult(int x, int y) 
{
    if (x >= y) return true;
    else return false;
}

int getPriority(char c) 
{
    if (c == '*' || c == '/') return 3;
    if (c == '+' || c == '-') return 2;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    stack<char> s;
    string str, result;
    cin >> str;
    
    for(char c : str) 
    {    
        if (c >= 'A') 
        {
            result.push_back(c);
            continue;
        }
        if (c == '(') s.push(c);
        else if (c == ')') 
        {
            while (1) 
            {
                char val = s.top();
                s.pop();
                if (val == '(') break;
                result.push_back(val);
            }
        }
        else 
        {
            while (1) 
            {
                int stackPriority = s.empty() ? -1 : getPriority(s.top());
                int newPriority = getPriority(c);
                if (pushToResult(stackPriority, newPriority)) 
                {
                    result.push_back(s.top());
                    s.pop();
                } 
                else 
                {
                    s.push(c);
                    break;
                }           
            }
        }
    }
    while (!s.empty()) 
    {
        result.push_back(s.top());
        s.pop();
    }
    
    cout << result;
    return 0;
}