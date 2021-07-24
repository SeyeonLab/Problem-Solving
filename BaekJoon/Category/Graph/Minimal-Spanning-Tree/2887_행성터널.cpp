#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

vector<pair<int, pair<int, int>>> info;
int parent[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);  cin.tie(NULL);

	int N; 	cin >> N;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({x, i});
		Y.push_back({y, i});
		Z.push_back({z, i});
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++) {
		info.push_back({ X[i + 1].first - X[i].first , {X[i].second, X[i + 1].second} });
		info.push_back({ Y[i + 1].first - Y[i].first , {Y[i].second, Y[i + 1].second} });
		info.push_back({ Z[i + 1].first - Z[i].first , {Z[i].second, Z[i + 1].second} });
	}

	sort(info.begin(), info.end());

	int cnt = 0;
	int total = 0;

	for (int i = 0; i < info.size(); i++) {
		int a = info[i].second.first;
		int b = info[i].second.second;
		int weight = info[i].first;

		if (find(a) != find(b)) {
			unite(a, b);
			total += weight;
		}
	}

	cout << total;

	return 0;
}