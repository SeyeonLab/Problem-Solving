#include <iostream>

using namespace std;

long long gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        long long sum = 0;
        cin >> n;
        
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(num[i], num[j]);
            }
        }
        cout << sum << '\n';
    }
}