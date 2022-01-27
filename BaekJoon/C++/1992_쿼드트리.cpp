#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int qtree[65][65];

void QuadTree(int sRow, int sCol, int eRow, int eCol){
    int check = qtree[sRow][sCol];
    for(int i = sRow; i < eRow; i++){
        for(int j = sCol; j < eCol; j++){
            if(check != qtree[i][j]){
                cout << '(';                
                QuadTree(sRow, sCol, (sRow+eRow)/2, (sCol+eCol)/2);
                QuadTree(sRow, (sCol+eCol)/2, (sRow+eRow)/2, eCol);
                QuadTree((sRow+eRow)/2, sCol, eRow, (sCol+eCol)/2);
                QuadTree((sRow+eRow)/2, (sCol+eCol)/2, eRow, eCol);
                cout << ')';
                return;
            }
        }
    }
    cout << check;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            qtree[i][j] = str[j] - '0';    
        }
    }
    
    QuadTree(0,0,N,N);
    
    return 0;
}