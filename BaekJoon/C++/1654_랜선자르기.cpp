#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
long long wire[10000];

bool possible (long long length) {
    int count = 0;

    for (int i = 0; i < K; i++)
        count += wire[i] / length;
            
    if (count >= N)
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> N;
    
    long long low = 1, high = 0, result = 0;
    
    for (int i = 0; i < K; i++) {
        cin >> wire[i];
        high = max(high, wire[i]);
    }
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (possible(mid)) {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    cout << result << '\n';
    return 0;
}