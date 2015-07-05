using namespace std;
#include <iostream>
int main() {
    int t, n; long long a[100];
    cin >> t;
    while(t --> 0) {
        long long res = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!(a[i]&1))
                res ^= ( a[i] >> 1);
            else {
                long long x = a[i];
                while(x&1) {
                    x >>= 1;
                }
                res ^= ( x >> 1 );
            }
        }
        if(!res)
            cout << "NO\n";
        else
            cout << "YES\n";

    }
    return 0;
}
