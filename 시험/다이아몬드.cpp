#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;
int TC;

int main()
{
	cin >> TC;
	for (int c = 1; c <= TC; c++) {
		int N, K;
		vector<int> dia;
		int maxCount = -1;
		cin >> N >> K;
		
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			dia.push_back(tmp);
		}
		
		sort(dia.begin(), dia.end());

		for (int i = 0; i < N; i++) {
			int countNum = 0;
			for (int j = i; j < N; j++) {
				if (dia[j]-dia[i] <= K) {
					countNum++;
				}	
			}
			if (countNum > maxCount)
				maxCount = countNum;
		}

		cout << "#" << c << " " << maxCount << endl;
		
	}
}