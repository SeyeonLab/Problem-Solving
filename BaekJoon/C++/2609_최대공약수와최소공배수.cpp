#include <iostream>

using namespace std;

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm (int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << '\n';
    cout << lcm(num1, num2) << '\n';
}