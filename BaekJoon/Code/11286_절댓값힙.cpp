#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int> 

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    priority_queue<P, vector<P>, greater<P>> pq;
    
    int N;  cin >> N;
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        
        if (x > 0) {
            pq.push({x, x});
        }
        else if (x < 0) {
            pq.push({-x, x});
        }
        else {
            if (!pq.empty()) {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
    }

    return 0;
}