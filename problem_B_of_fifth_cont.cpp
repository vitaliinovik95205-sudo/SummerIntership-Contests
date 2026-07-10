#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--){
        
        vector<int> digs;
        ll n;
        cin >> n;
        
        if (n == 0){
            cout << 10 << endl;
            continue;
        }
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        
        for (int x = 9; x >= 2; x--) {
            while (n % x == 0) {
                digs.push_back(x);
                n /= x;
            }
        }
        
        if (n > 1){
            cout << -1 << endl;
            continue; 
        }
        
        sort(digs.begin(), digs.end());

        string str = "";
        for (int j : digs){
            str += char('0' + j);
        }
        cout << str << "\n";
    }
    
    return 0;
}
