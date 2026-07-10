#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        unordered_map<long long, int> last_pos;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < n; right++) {
            long long x;
            cin >> x;
            
            if (last_pos.find(x) != last_pos.end() && last_pos[x] >= left) {
                left = last_pos[x] + 1;
            }
            
            last_pos[x] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        cout << max_len << "\n";
    }
    
    return 0;
}
