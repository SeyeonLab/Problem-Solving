#include <iostream>
#include <vector>

using namespace std;
string op;
vector<bool> S(21);
int M, x;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> op;
        if (op.compare("add") == 0) {
            cin >> x;
            S[x] = true;
        }
        else if (op.compare("remove") == 0) {
            cin >> x;
            S[x] = false;
        }
        else if (op.compare("check") == 0) {
            cin >> x;
            if (S[x]) cout << 1 << '\n';
            else cout << 0 << '\n';           
        }
        else if (op.compare("toggle") == 0) {
            cin >> x;
            if (S[x]) S[x] = false;
            else S[x] = true;
        }
        else if (op.compare("all") == 0) {
            for (int i = 1; i <= 20; i++)
                S[i] = true;
        }
        else if (op.compare("empty") == 0) {
            for (int i = 1; i <= 20; i++)
                S[i] = false;
        }
    }
        
    return 0;
}