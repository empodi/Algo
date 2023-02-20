#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int N;
long long ans;
int A[MAX + 1];
int tmp[MAX + 1];

void merge(int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = 0;
    while (i <= mid && j <= hi) {
        if (A[i] <= A[j]) tmp[k++] = A[i++];
        else {
            ans += mid - i + 1;
            tmp[k++] = A[j++];
        }
    }
    while (i <= mid) tmp[k++] = A[i++];
    while (j <= hi) tmp[k++] = A[j++];
    for (int i = lo; i <= hi; i++) A[i] = tmp[i - lo];
}

void mergeSort(int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        mergeSort(lo, mid);
        mergeSort(mid + 1, hi);
        merge(lo, mid, hi);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        ans = 0;
        cin >> N;
        for (int j = 0; j < N; j++) cin >> A[j];
        mergeSort(0, N - 1);
        cout << '#' << i << ' ' << ans << '\n';
    }
    return 0;
}