#include <iostream>
#include <set>

using namespace std;
set<string> list;
set<string> result;
int N, M;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    string name;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> name;
        list.insert(name);
    }    
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (list.insert(name).second == false)
            result.insert(name);
    }
    cout << result.size() << '\n';
    for (set<string>::iterator it = result.begin(); it != result.end(); it++)
        cout << *it << '\n';
        
    return 0;
}