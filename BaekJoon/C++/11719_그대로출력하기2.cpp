#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); // 입력을 다 받기 전까지는 cout하지 않도록 함.
    string s;
    while (getline(cin, s)) {
            cout << s << '\n';
    }
}