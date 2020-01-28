#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	int maxNum;
	int minNum;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (i == 0) {
			maxNum = a;
			minNum = a;
		}
		else if (a > maxNum) {
			maxNum = a;
		}
		else if (a < minNum) {
			minNum = a;
		}
	}

	cout << minNum << " " << maxNum << endl;

}	