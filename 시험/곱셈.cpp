#include<iostream>

using namespace std;

int main()
{
	int A, B, C, D, E, F;
	cin >> A >> B;
	C = A * (B % 10);
	D = A * ((B / 10) % 10);
	E = A * (B / 100);
	F = A * B;

	cout << C << endl << D << endl << E << endl << F << endl;

}