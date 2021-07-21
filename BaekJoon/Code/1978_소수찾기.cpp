#include <iostream>

using namespace std;
const int MN = 1001;

bool sieve[MN];

int main(void) {
    sieve[0] = true; sieve[1] = true;
    for (int i = 2; i * i < MN; i++) {
        if (sieve[i]) 
            continue;
        for (int p = i * i; p < MN; p += i)
            sieve[p] = true;
    }

    int n;
    int count = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!sieve[num])
            count++;
    }
    cout << count;
}