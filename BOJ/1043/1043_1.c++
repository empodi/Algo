#include <bits/stdc++.h>
using namespace std;

int numOfParty;    // 사람 수
int numOfPeople;    // 파티 수
int numOfTruth;    // 진실을 아는 사람의 수

vector<int> whoKnowsTruth;    // 진실을 아는 사람 번호 저장

vector<vector<int>> partyGraph (51, vector<int>{});    // 각각의 파티에 참석하는 사람들의 번호 저장
vector<vector<int>> personGraph (51, vector<int>{});    // 각 사람들이 몇 번 파티에 가는지 저장

bool checkPeople[51];    // 진실을 아는 사람 중 어떤 파티에 가는지 확인된 사람 체크
bool checkParty[51];    // 가도 되는 파티인지 체크

void init() {
    
    for (int i = 1; i <= numOfPeople; i++)
        checkPeople[i] = true;
    
    cin >> numOfPeople >> numOfParty;
    cin >> numOfTruth;
    
    for (int i = 0; i < numOfTruth; i++) {
        int x; cin >> x;
        whoKnowsTruth.push_back(x);
        checkPeople[x] = false;
    }
    
    for (int i = 1; i <= numOfParty; i++) {
        int num; cin >> num;
        
        while (num--) {
            int person; cin >> person;
            partyGraph[i].push_back(person);
            personGraph[person].push_back(i);
        }
        checkParty[i] = true;
    }
}

int solve() {
    
    if (numOfTruth == 0) return numOfParty;
    
    for (int i = 0; i < whoKnowsTruth.size(); i++) {
        
        int n = whoKnowsTruth[i];
        
        queue<int> q;
        q.push(n);
        
        while (!q.empty()) {
            
            int person = q.front();
            q.pop();
            
            if (checkPeople[person]) continue;
            checkPeople[person] = true;
            
            for (int k = 0; k < personGraph[person].size(); k++) {
                int party = personGraph[person][k];
                
                if (checkParty[party] == false) continue;
                checkParty[party] = false;
                
                for (int j = 0; j < partyGraph[party].size(); j++) {
                    q.push(partyGraph[party][j]);
                }
            }
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= numOfParty; i++) {
        if (checkParty[i]) cnt++;
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    cout << solve();
    
    return 0;
}
