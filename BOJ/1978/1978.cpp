#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int arr[1001];

int main() {
    
    memset(arr, 1, sizeof(arr));
    arr[1] = 0;
    int len, val, cnt = 0;
    cin >> len;
    
    while (len-- > 0) {
        cin >> val;
        for (int i = 2; i <= sqrt(val); i++) {
            if (arr[i] == 0) continue;
            for (int j = i + i; j <= val; j+= i ) {
                arr[j] = 0;
            }
        }
        if (arr[val]) cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}