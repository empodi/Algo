#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string binary(long long n) {
    string ret;
    while (n) {
        int mod = n % 2;
        ret += to_string(mod);
        n /= 2;
    }
    return ret;
}

bool check(const string& s, int left, int right, char parent)
{
    if (left > right) return true;
    int mid = (left + right) / 2;
    if (parent == '0' && s[mid] == '1') return false;
    if (check(s,left,mid-1,s[mid]) && check(s,mid+1,right,s[mid]))
        return true;
    return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    int A[2000] = {0,};
    for (int i = 0; i <= 10; i++) A[((2<<i) - 1)] = 1; 
    for (long long n : numbers) {
        string s = binary(n);
        while (A[s.length()] == 0) s += '0';
        reverse(s.begin(),s.end());
        //cout << s << '\n';
        answer.push_back(check(s,0,s.length()-1,'1'));
    }
    return answer;
}