#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>


using namespace std;

int F;
int answer;
map<string, pair<string, int>> mymap;

string find(string x) {
    if (mymap[x].first.compare(x) == 0) return x;
    return mymap[x].first = find(mymap[x].first);
}

void unite(string x, string y) {
    x = find(x), y = find(y);
    if (x.compare(y) == 0) {
        answer = mymap[x].second;
        return;
    }
    mymap[y].first = x;
    mymap[x].second += mymap[y].second;
    answer = mymap[x].second;
}

int main(void) {
    int T;  cin >> T;

    while (T--) {
        scanf("%d", &F);
        mymap.clear();

        for (int i = 0; i < F; i++) {
            answer = 0;
            char n1[21], n2[21];
            scanf("%s %s", n1, n2);
            string s1(n1);
            string s2(n2);

            if ((mymap.count(s1) == 0) && (mymap.count(s2) == 0)) {
                mymap[s1].first = s1;
                mymap[s2].first = s2;
                mymap[s1].second++;
                mymap[s2].second++;
                unite(s1, s2);
            }
            else if ((mymap.count(s1) > 0) && (mymap.count(s2) == 0)) {
                mymap[s2].first = s2;
                mymap[s2].second++;
                unite(s1, s2);
            }
            else if ((mymap.count(s1) == 0) && (mymap.count(s2) > 0)) {
                mymap[s1].first = s1;
                mymap[s1].second++;
                unite(s1, s2);
            }else {
                unite(s1, s2);
            }

            printf("%d\n", answer);
        }
    }

    return 0;
}
