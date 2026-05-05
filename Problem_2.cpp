#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
    long long k;
    cin >> k;
    
    long long rem = a[0] % k;
    for (int i = 1; i < n; i++) {
        if (a[i] % k != rem) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<long long> steps(n);
    for (int i = 0; i < n; i++) steps[i] = a[i] / k;
    
    sort(steps.begin(), steps.end());
    long long median = steps[n / 2];
    
    long long totalOps = 0;
    for (int i = 0; i < n; i++) {
        totalOps += abs(steps[i] - median);
    }
    
    cout << totalOps << endl;
    return 0;
}
