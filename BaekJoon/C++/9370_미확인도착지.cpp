#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
#define endl "\n"

using namespace std;
const int INF = 1e9;
const int MAX = 2001;

int N, M, T, S, G, H, Dist_GH;
int Dist_S[MAX];
int Dist_G[MAX];
int Dist_H[MAX];
 
vector<pair<int,int>> V[MAX];
vector<int> Candidate;
 
void Initialize() {
    for (int i = 0; i < MAX; i++) {
        V[i].clear();
        Dist_S[i] = INF;
        Dist_G[i] = INF;
        Dist_H[i] = INF;
    }
    Candidate.clear();
}
 
void Input() {
    cin >> N >> M >> T;
    cin >> S >> G >> H;

    for (int i = 0; i < M; i++) {
        int a, b, d; cin >> a >> b >> d;
        V[a].push_back(make_pair(d, b));
        V[b].push_back(make_pair(d, a));
    }

    for (int i = 0; i < T; i++) {
        int x; cin >> x;
        Candidate.push_back(x);
    }
}
 
void Dijkstra(int Start, int A[MAX]) {
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    A[Start] = 0;
 
    while (!PQ.empty()) {
        int Cost = PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < V[Cur].size(); i++) {
            int nCost = V[Cur][i].first;
            int Next = V[Cur][i].second;
 
            if (A[Next] > Cost + nCost)
            {
                A[Next] = Cost + nCost;
                PQ.push(make_pair(A[Next], Next));
            }
        }
    }
}
 
void Solution() {
    Dijkstra(S, Dist_S);
    Dijkstra(G, Dist_G);
    Dijkstra(H, Dist_H);
    Dist_GH = Dist_G[H];

    sort(Candidate.begin(), Candidate.end());
    for (int i = 0; i < Candidate.size(); i++) {
        int Dest = Candidate[i];
        if (Dist_S[Dest] == Dist_S[G] + Dist_GH + Dist_H[Dest]) cout << Dest << " ";
        else if (Dist_S[Dest] == Dist_S[H] + Dist_GH + Dist_G[Dest]) cout << Dest << " ";
    }
    cout << endl;    
}
 
void Solve() {
    int T; cin >> T;
    while (T--) {
        Initialize();
        Input();
        Solution();
    }
}
 
int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    Solve(); 
    return 0;
}