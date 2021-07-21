#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    if(b.second > a.second)
        return true;
    else if(b.second == a.second){
        if(b.first > a.first)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < n; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
        
    return 0;
}