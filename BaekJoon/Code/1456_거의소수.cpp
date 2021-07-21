#include <iostream>
#include <vector>

using namespace std;

const int val = 10000001;
bool check[val];
vector<int> prime;

int main(void) {
    check[0] = true; check[1] = true;
    for (int i = 2; i < val; i++) {
        if (check[i]) continue;
        prime.push_back(i);
        for (int p = 2 * i; p < val; p += i) {
            check[p] = true;
        }
    }
    long long a, b;
    cin >> a >> b;

    long long int count = 0;
    for (auto it : prime) {
        long long curr = 1LL * it;
        long long temp = curr;
        while (temp <= b / curr) {
            temp *= curr;
            if (temp >= a) count++;
        }
    }
    cout << count << '\n';
    return 0;
}