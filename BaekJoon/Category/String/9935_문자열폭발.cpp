#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    
    vector<string> v;
    string str, bomb, answer = "";

    cin >> str >> bomb;
    
    for (int i = 0; i < str.size(); i++) {
        answer += str[i];

        if (answer[answer.length() - 1] == bomb[bomb.length() - 1]) {
            int count = 0;

            if (answer.length() >= bomb.length()) {
                for (int j = 1; j <= bomb.length(); j++) {
                    if (answer[answer.length() - j] == bomb[bomb.length() - j]) {
                        count++;
                    }
                }

                if (bomb.length() == count) {
                    for (int k = 0; k < bomb.size(); k++) {
                        answer.pop_back();
                    }
                }
            }
        }
    }

    if (answer.size()) cout << answer << '\n';
    else cout << "FRULA" << '\n';

    return 0;
}