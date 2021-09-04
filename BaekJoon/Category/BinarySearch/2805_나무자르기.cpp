#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long tree[1000001];

bool possible (long long height) {
    long long len = 0;

    for (int i = 0; i < N; i++) 
        if (tree[i] > height) 
            len += tree[i] - height;    
            
    if (len >= M)
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    long long low = 1, high = 0, result = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        high = max(high, tree[i]);
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