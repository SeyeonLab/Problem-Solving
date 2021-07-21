#include <string>
#include <vector>

using namespace std;
string solution(int a, int b) {
    int cnt = 0;
    string answer = "";
    vector<int> v = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> w = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    for(int i = 0; i < a-1; i++){
        cnt += v[i];
    }
    cnt += b;
    answer = w[cnt % 7];
    
    return answer;
}