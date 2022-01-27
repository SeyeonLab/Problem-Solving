#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, mymin = 3333333;
int S[20][20] = {};
bool selected[20] = {};

void startlink(int num, int cnt){
    vector<int> start_team;
    vector<int> link_team;
    int start_score = 0;
    int link_score = 0;
    
    if(cnt == N / 2){
        for(int i = 0; i < N; i++){
            if(selected[i] == true)
                start_team.push_back(i);
            else
                link_team.push_back(i);
        }
        
        for(int i = 0; i < (N/2); i++){
            for(int j = 0; j < (N/2); j++){
                start_score += S[start_team[i]][start_team[j]];
                link_score += S[link_team[i]][link_team[j]];
            }
        }
        
        if(abs(start_score - link_score) < mymin)
            mymin = abs(start_score - link_score);
        
        return;
    }
    
    for(int i = num; i < N; i++){
        if(!selected[i]){
            selected[i] = true;
            startlink(i, cnt + 1);
            selected[i] = false;
        }
    }
    
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &S[i][j]);
        }
    }
    startlink(0, 0);
    printf("%d", mymin);
    
    return 0;
}