#include<iostream>

using namespace std;

int main()
{
	long long A, B, C ,i;
	cin >> A >> B >> C;
	
	if (B >= C) {
		cout << "-1" << endl;
	}
	else {
		i = A / (C - B) + 1;
		cout << i << endl;

	}

} 