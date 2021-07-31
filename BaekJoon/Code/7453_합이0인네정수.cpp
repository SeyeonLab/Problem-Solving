#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
long long answer = 0;
vector<int> sum1, sum2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> A[i] >> B[i] >> C[i] >> D[i];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum1.push_back(A[i] + B[j]);
			sum2.push_back(C[i] + D[j]);
		}	
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	
	for (int i = 0; i < sum1.size(); i++) {
		int B_pre = lower_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
		int B_end = upper_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();

		answer += (B_end - B_pre);
	}

	cout << answer << endl;
	
	return 0;

}