#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long X, Y, Z;
long long budget[10001];

long long WinRate(long long num, long long win) {
    return win * 100 / num;
}

bool possible (long long game) {
    long long sum = 0;
    long long tempX, tempY, tempZ;

    tempX = X + game;
    tempY = Y + game;
    tempZ = WinRate(tempX, tempY);

    if (tempZ >= Z + 1)
        return true;

    return false;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> X >> Y;
    Z = WinRate(X, Y);

    if (Z >= 99) {
        cout << -1 << '\n';
        return 0;
    }

    long long low = 1, high = 1e9, result = 1e9;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (possible(mid)) {
            result = min(result, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;            
    }

    cout << result << '\n';
    
    return 0;
}