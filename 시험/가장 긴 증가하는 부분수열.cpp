#include<iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1002];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int dp[1001];
	int sol = 1;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sol = max(sol, dp[i]);
	}
	cout << sol << endl;
}