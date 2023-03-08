#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INIT 100
#define UNLOAD 200
#define DELETE 300
#define CHECK 400
#define BREAK 500
#define MAX_BOX 100000
#define MAX_BELT 10
using namespace std;
typedef long long ll;

int Q, boxNum, beltNum;
struct box {
    int id;
    int weight;
    struct box *prev;
    struct box *next;
};

int cnt;
box pool[MAX_BOX + 10];
bool broken[MAX_BELT + 1];
box belt[MAX_BELT + 1]; // starts with dummy
box *lastBelt[MAX_BOX + 10];
unordered_map<int,int> idHash;
unordered_map<int,int> idPool;

void display() {
    for (int i = 1; i <= beltNum; i++) {
        box *tmp = &belt[i];
        if (!tmp) continue;
        cout << i << ": ";
        tmp = tmp->next;
        while (tmp) {
            cout << "(" << tmp->id << ", " << tmp->weight << ")  ";
            tmp = tmp->next;
        }
        if (lastBelt[i]) cout << "  ... last: " << lastBelt[i]->id << '\n';
        else cout << " ... last is NULL \n";
    }
}

bool boxIdExists(const int & id) {
    if (idHash.find(id) == idHash.end() || idHash[id] == -1) return false;
    if (idPool.find(id) == idHash.end() || idPool[id] == -1) return false;
    return true;
}

void init() {
    cin >> boxNum >> beltNum;
    cnt = 0;
    for (int i = 0; i <= boxNum; i++) {
        broken[i] = false;
        lastBelt[i] = nullptr;
    }
    for (int i = 0; i <= MAX_BELT; i++) {
        belt[i].id = belt[i].weight = 0;
        belt[i].prev = belt[i].next = nullptr;
    }

    int tmpBox[MAX_BOX + 10] = {0,}, tmpWeight[MAX_BOX + 10] = {0,};
    for (int i = 0; i < boxNum; i++) cin >> tmpBox[i];
    for (int i = 0; i < boxNum; i++) cin >> tmpWeight[i];
    int K = boxNum / beltNum;
    for (int k = 1; k <= beltNum; k++) {
        box *cur = &belt[k];
        for (int j = 0; j < K; j++) {
            int i = j + (k - 1) * K;
            pool[cnt].id = tmpBox[i];
            pool[cnt].weight = tmpWeight[i];
            cur->next = &pool[cnt];
            pool[cnt].prev = cur;
            pool[cnt].next = nullptr;
            cur = &pool[cnt];
            lastBelt[k] = cur;
            idHash[tmpBox[i]] = k;
            idPool[tmpBox[i]] = cnt;
            cnt++;
        }
    }
}

ll unload(const int & K) {
    ll ret = 0;
    for (int i = 1; i <= beltNum; i++) {
        if (broken[i]) continue;
        if (belt[i].next == nullptr) continue;
        if (belt[i].next->weight <= K) { // 하차 진행
            ret += (ll) belt[i].next->weight;
            idHash[belt[i].next->id] = -1;
            idPool[belt[i].next->id] = -1;
            box *tmp = belt[i].next->next;
            belt[i].next = tmp;
            if (belt[i].next == nullptr) lastBelt[i] = nullptr;
            if (tmp) tmp->prev = &belt[i];
        }
        else { // 맨 앞 박스를 맨 뒤로
            box *first = belt[i].next;
            if (first->next == nullptr) continue;
            box *last = lastBelt[i];
            belt[i].next = first->next;
            if (first->next) first->next->prev = &belt[i];
            last->next = first;
            first->prev = last;
            first->next = nullptr;
            lastBelt[i] = first;
        }
    }
    return ret;
}

int deleteBox(const int & id) {
    if (boxIdExists(id) == false) return -1;
    int beltIdx = idHash[id];
    if (!belt[beltIdx].next) return -1;
    box *cur = &pool[idPool[id]];

    box *before = cur->prev;
    box *after = cur->next;
    before->next = after;
    if (after) after->prev = before;
    idHash[id] = -1;
    idPool[id] = -1;
    if (before->next == nullptr) { // 마지막 상자를 삭제한 경우
        if (before->id == 0) lastBelt[beltIdx] = nullptr; // 상자가 하나도 안 남은 경우
        else lastBelt[beltIdx] = before; // 마지막 상자 업데이트
    }
    return id;
}

int checkBox(const int & id) {
    if (boxIdExists(id) == false) return -1;
    int beltIdx = idHash[id];
    if (!belt[beltIdx].next) return -1;
    if (belt[beltIdx].next->id == id || lastBelt[beltIdx] == belt[beltIdx].next) {
        return beltIdx;
    }
    box *cur = &pool[idPool[id]];
    box *first = belt[beltIdx].next;
    box *before = cur->prev;
    box *last = lastBelt[beltIdx];

    before->next = nullptr;
    lastBelt[beltIdx] = before;
    cur->prev = nullptr;

    belt[beltIdx].next = cur;
    cur->prev = &belt[beltIdx];
    if (last == nullptr) last = cur;
    last->next = first;
    first->prev = last;
    return beltIdx;
}

int deleteBelt(const int & targetBelt) {
    if (targetBelt < 1 || targetBelt > beltNum || broken[targetBelt] || beltNum == 1) return -1;
    broken[targetBelt] = true;
    box *cur = belt[targetBelt].next;
    belt[targetBelt].next = nullptr;
    int i = targetBelt;
    while (true) {
        i = (i + 1) % (beltNum + 1);
        if (i == 0) i++;
        if (broken[i]) continue;
        box *tmp = cur;
        while (tmp) {
            idHash[tmp->id] = i;
            tmp = tmp->next;
        }
        box *last = lastBelt[i];
        last->next = cur;
        if (cur) cur->prev = last;
        lastBelt[i] = lastBelt[targetBelt];
        lastBelt[targetBelt] = nullptr;
        break;
    }
    return targetBelt;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> Q;
    while (Q--) {
        int opt, id;
        cin >> opt;
        if (opt == INIT) {
            init();
//            display();
        }
        else if (opt == UNLOAD) {
            int K;
            cin >> K;
            ll res = unload(K);
            cout << res << '\n';
//            display();
        }
        else if (opt == DELETE) {
            cin >> id;
            int res = deleteBox(id);
            cout << res << '\n';
//            display();
        }
        else if (opt == CHECK) {
            cin >> id;
            int res = checkBox(id);
            cout << res << '\n';
//            display();
        }
        else if (opt == BREAK) {
            int b_num;
            cin >> b_num;
            int res = deleteBelt(b_num);
            cout << res << '\n';
//            display();
        }
    }
    return 0;
}