#include<iostream>
#include<string.h>

using namespace std;
int T;
int minSum = 99999;
//최소값 마지막 N
void BFS(int sum,int index,int N,int M,char color,bool check,string* map)
{
	if (index == N - 1) {
		if(sum < minSum && check == true)
			minSum = sum;

		return;
	}
	
	if (color == 'B')
		check = true;

	for (int i = 0; i < M; i++) {
		if (map[index][i] != color)
			sum++;
	}

	if (color == 'W') {
		BFS(sum, index + 1, N, M, 'W',check ,map);

		BFS(sum, index + 1, N, M, 'B', check,map);
	}
	else if (color == 'B') {
		BFS(sum, index + 1, N, M, 'B', check, map);

		BFS(sum, index + 1, N, M, 'R', check,map);
	}
	else if (color == 'R') {
		BFS(sum, index + 1, N, M, 'R', check,map);
	}
	
}

int main()
{
	cin >> T;
	for (int c = 1; c <= T; c++) {
		int N, M;
		cin >> N >> M;
		string map[51];
		int countNum = 0;

		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		for (int j = 0; j < M; j++) {
			if (map[0][j] != 'W')
				countNum++;
			
			if (map[N-1][j] != 'R')
				countNum++;
		}

		BFS(countNum, 1, N, M, 'W', false,map);
		BFS(countNum, 1, N, M, 'B', false,map);

		cout << "#" << c << " " << minSum<<endl;
		minSum = 99999;
	}
}