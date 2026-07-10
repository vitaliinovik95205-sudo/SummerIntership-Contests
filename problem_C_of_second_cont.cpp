#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int a[6000];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a, a + N);
    
    long long count = 0;
    
    for (int k = 2; k < N; k++) {
        int i = 0;
        int j = k - 1;
        
        while (i < j) {
            if (a[i] + a[j] > a[k]) {
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
