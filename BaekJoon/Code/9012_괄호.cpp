#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int T;
    bool check = false;
    cin >> T;
    
    while (T--) {
        string str;
        check = false;
        stack<char> s;
        
        cin >> str;
        
        for (int i = 0; i < str.size(); i++) {
            if(str[i] == '(')
                s.push(str[i]);
            else {
                if (!s.empty())
                    s.pop();
                else {
                    cout << "NO" << endl;
                    check = true;
                    break;
                }
            }
        }
        
        if(check)
            continue;
        
        if (s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}