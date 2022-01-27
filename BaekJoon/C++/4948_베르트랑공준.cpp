#include <iostream>

using namespace std;
const int maxi = 250000;
bool check[maxi];

int main(void) {
    check[0] = true; check[1] = true;
    for (int i = 2; i * i <= maxi; i++) {
        if (check[i]) continue;
        for (int p = i * i; p <= maxi; p += i) {
            check[p] = true;
        }
    }
    while (1) {
        int num, count;
        count = 0;
        cin >> num;
        if (num == 0)
            break;
        for (int i = num + 1; i <= num * 2; i++) {
            if (!check[i]) count++;
        }
        cout << count << '\n';
    }
}