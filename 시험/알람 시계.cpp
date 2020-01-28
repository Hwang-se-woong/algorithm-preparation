#include<iostream>

using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;
	
	int RM = M - 45;

	if (RM < 0) {
		RM = 60 + RM;
		H--;

		if (H < 0)
			H = 23;
	}
		
	cout << H << " " << RM << endl;
}