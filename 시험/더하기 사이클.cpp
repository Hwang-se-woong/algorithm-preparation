#include<iostream>

using namespace std;

int main()
{
	int num;
	int count = 0;
	cin >> num;
	int tmp = num;

	while (1) {
		int nextNum;

		if (tmp < 10) {
			nextNum = (tmp * 10) + tmp;
		}
		else {
			nextNum = (tmp % 10) * 10 + (((tmp / 10) + (tmp % 10))%10);
		}
		
		tmp = nextNum;
		count++;

		if (nextNum == num) {
			cout << count << endl;
			return 0;
		}
	}
	
}