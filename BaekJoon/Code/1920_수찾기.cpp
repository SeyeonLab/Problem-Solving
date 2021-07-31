#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    int N;  cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    int M;  cin >> M;
    for (int i = 0; i < M; i++) {
        int key;  cin >> key;
        if (binary_search(A, A + N, key)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}

/*
void binary_search(int val, int n){
    int start = 0;
    int end = n-1;
    int mid;
    
    while(end - start >= 0){
        mid = (start+end)/2;
        if(arr[mid] == val){
            cout << '1' << '\n';
            return;
        }
        else if(arr[mid] > val)
            end = mid-1;
        else if(arr[mid] < val)
            start = mid+1;
    }
    
    cout << '0' << '\n';
    return;
}
*/