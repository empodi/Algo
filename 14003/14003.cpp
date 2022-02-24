#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int len, val;
    cin >> len;
    
    vector<int> v;
    
    for (int i = 0 ; i < len ;i++) {
        cin >> val;
        v.push_back(val);
    }
    
    vector<int> nums;
    vector<int> idxArray(len);
    
    for (int i = 0; i < len; i++) {
        
        if (nums.empty()) {
            nums.push_back(v[i]);
            idxArray[i] = 0;
            continue;
        }
        
        if (v[i] > nums.back()) {
            nums.push_back(v[i]);
            idxArray[i] = nums.size() - 1;
        }
        else {
            auto it = lower_bound(nums.begin(), nums.end(), v[i]);
            *it = v[i];
            
            idxArray[i] = distance(nums.begin(), it);
        }
    }
    
    int pos = nums.size() - 1, idx = len - 1;
    vector<int> ans;
    
    while (idx >= 0 && pos >= 0) {
        
        while (idxArray[idx] != pos) idx--;
        
        ans.push_back(v[idx]);
        idx--;
        pos--;
    }

    cout << nums.size() << "\n";
    
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}