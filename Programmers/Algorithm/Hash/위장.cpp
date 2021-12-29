#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> mymap;
    int answer = 1;
    
    for (int i = 0; i < clothes.size(); i++) {
        if (mymap.count(clothes[i][1]) > 0)
            mymap[clothes[i][1]]++;
        else
            mymap.insert(make_pair(clothes[i][1], 1));
    }
    
    for (auto it : mymap) answer *= it.second + 1;    
    answer--;

    return answer;
}

// 각 종류를 key로 하는 value에 옷을 입지 않는 경우를 포함해 각 종류별로 전부 곱하고 마지막으로 아예 옷을 입지 않는 경우를 뺀 값이 결과