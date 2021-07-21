#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<char> v;
    
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), greater<char>());
    
    for(vector<char>::iterator iter = v.begin(); iter != v.end(); iter++)
        cout << *iter;
}