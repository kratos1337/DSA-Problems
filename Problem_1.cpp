#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    string t = s + s;
    int len = t.size();
    
    int freq[26] = {};
    int duplicates = 0;
    long long curSum = 0;
    long long maxSum = 0;
    int left = 0;
    
    for (int right = 0; right < len; right++) {
        if (right - left >= n) {
            int c = t[left] - 'a';
            curSum -= (c + 1);
            freq[c]--;
            if (freq[c] >= 1) duplicates--;
            left++;
        }
        
        int c = t[right] - 'a';
        freq[c]++;
        curSum += (c + 1);
        if (freq[c] == 2) duplicates++;
        
        while (duplicates > 0) {
            int lc = t[left] - 'a';
            curSum -= (lc + 1);
            freq[lc]--;
            if (freq[lc] == 1) duplicates--;
            left++;
        }
        
        maxSum = max(maxSum, curSum);
    }
    
    cout << maxSum << endl;
    return 0;
}
