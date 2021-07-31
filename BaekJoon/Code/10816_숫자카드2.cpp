#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    int N;  cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int M;  cin >> M;
    for (int i = 0; i < M; i++) {
        int key;  cin >> key;
        cout << upper_bound(arr, arr + N, key) - lower_bound(arr, arr + N, key) << ' ';
    }
}