#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MODUL = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll l, r;
    cin >> l >> r;
    
    vector<int> dp(r + 1, 0);
    dp[1] = 1;  
    
    ll ans = 0;
    
    for (int i = 1; i <= r; i++) {
        if (i >= l) {
            ans += dp[i];
            if (ans >= MODUL) ans -= MODUL;
        }
        
        if (dp[i] == 0) continue;
        
        for (int j = 2 * i; j <= r; j += i) {
            dp[j] += dp[i];
            if (dp[j] >= MODUL) dp[j] -= MODUL;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
