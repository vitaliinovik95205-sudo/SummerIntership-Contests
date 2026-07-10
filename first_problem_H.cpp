#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    int k;
    cin >> n >> k;
    
    if (k == 0) {
        if (n % 2 == 1) {
            cout << n << endl;
        } 
        else {
            cout << n - 1 << endl;
        }
        return 0;
    }
    
    ll power2k = 1;
    for (int i = 0; i < k; i++) {
        power2k *= 2;
        if (power2k > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    ll m = (n / power2k) * power2k;
    
    if ((m / power2k) % 2 == 0) {
        m -= power2k;
    }
    
    if (m > 0) {
        cout << m << endl;
    } 
    else {
        cout << -1 << endl;
    }
    
    return 0;
}
