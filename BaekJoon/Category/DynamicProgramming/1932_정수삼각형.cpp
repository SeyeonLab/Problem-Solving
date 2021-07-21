#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tri[501][501];
int M[501][501];

int main() {
    int n, mymax = -1;
    cin >> n;
    cin >> tri[1][1];
    M[1][1] = tri[1][1];
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
            
            if(j == 1)
                M[i][j] = M[i-1][j] + tri[i][j];
            else if(j == i)
                M[i][j] = M[i-1][j-1] + tri[i][j];
            else
                M[i][j] = tri[i][j] + max(M[i-1][j-1], M[i-1][j]);
            
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(M[n][i] > mymax){
            mymax = M[n][i];
        }
    }
    
    cout << mymax << endl;
    
    return 0;
}