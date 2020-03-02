#include<iostream>

using namespace std;

int main()
{
	int maxNum = -1;
	int index = 0;

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		if (num > maxNum) {
			maxNum = num;
			index = i+1;
		}
	}

	cout << maxNum << endl << index << endl;
}