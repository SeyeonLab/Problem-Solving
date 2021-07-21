#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> umap;
    unordered_map<string, int>::iterator it;
    
    for (int i = 0; i < participant.size(); i++) umap[participant[i]]++;
    for (int i = 0; i < completion.size(); i++) umap[completion[i]]--;
    for (it = umap.begin(); it != umap.end(); it++) {
        if (it->second != 0) answer = it->first;
    }
    
    return answer;
}