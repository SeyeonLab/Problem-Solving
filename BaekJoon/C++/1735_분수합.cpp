#include <iostream>

using namespace std;

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm (int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    int num1, num2, num3 ,num4;
    int up, down, gcd_val;
    cin >> num1 >> num2 >> num3 >> num4;
    down = lcm(num2, num4);
    up = (num1 * (down / num2)) + (num3 * (down / num4));
    gcd_val = gcd(up, down);
    if (up % gcd_val == 0 && down % gcd_val == 0) {
        up /= gcd_val;
        down /= gcd_val;
    }
    cout << up << ' ' << down;
}