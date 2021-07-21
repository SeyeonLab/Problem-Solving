#include<iostream>
#include<string>

using namespace std;

int gcd (int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm (int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    string s, t, ss, tt;
	cin >> s >> t;

	int temp = lcm(s.size(), t.size());

	for (int i = 0; i < temp / s.size(); i++)
		ss += s;

	for (int i = 0; i < temp / t.size(); i++)
		tt += t;

	if (ss == tt) cout << 1 << '\n';
	else cout << 0 << '\n';
}