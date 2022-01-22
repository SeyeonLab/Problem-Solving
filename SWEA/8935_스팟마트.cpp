#include <iostream>
#include <string>

#define MAXN 3001
#define MAXM 101

using namespace std;

int test_case;
int T, N, M;
int A[MAXN];
int B[MAXM];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> A[i];
        cin >> M;
        for (int i = 1; i <= M; ++i) cin >> B[i];

        cout << "#" << test_case << " " <<  << '\n';
	}
	return 0;
}