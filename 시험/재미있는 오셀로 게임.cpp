#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

int T;
int N, M;
int map[9][9];
int dirX[8] = { -1,-1,0,1,1,1,0,-1 };
int dirY[8] = { 0,1,1,1,0,-1,-1,-1 };

void init(int size)
{
	memset(map, 0, sizeof(map));
	map[size / 2][size / 2] = 2;
	map[size / 2 + 1][size / 2] = 1;
	map[size / 2][size / 2 + 1] = 1;
	map[size / 2+1][size / 2+1] = 2;
}

struct stone {
	int x, y;
};

int main()
{
	cin >> T;
	
	int sol_num = 1;

	while (T--) {
		cin >> N >> M;
		int b_count = 0;
		int w_count = 0;
		init(N);

		for (int i = 0; i < M; i++) {
			int x, y, color; // color= 1: black 2: white
			cin >> x >> y >> color;
			map[y][x] = color;

			for (int j = 0; j < 8; j++) {
				
				int checkX = y + dirX[j];
				int checkY = x + dirY[j];
				vector<stone> changeList;
				int check = 0;

				while (checkX > 0 && checkY > 0 && checkX <= N && checkY <= N && map[checkX][checkY] != 0) {
					if (map[checkX][checkY] != map[y][x]) {
						stone Stone;
						Stone.x = checkX;
						Stone.y = checkY;
						changeList.push_back(Stone);
						checkX += dirX[j];
						checkY += dirY[j];
					}
					else {
						check = 1;
						break;
					}
				}

				if (check && changeList.size() > 0)
				{
					for (int i = 0; i < changeList.size(); i++) {
						map[changeList[i].x][changeList[i].y] = color;
					}
				}
			}

			//for (int i = 1; i <= N; i++) {
			//	for (int j = 1; j <= N; j++) {
			//		cout << map[i][j] << " ";
			//	}
			//	cout << endl;
			//}
			//cout << endl;
		}



		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 1)
					b_count++;
				else if (map[i][j] == 2)
					w_count++;
			}
		}

		cout << "#" << sol_num <<" "<< b_count << " " << w_count << endl;
		sol_num++;
	}
}