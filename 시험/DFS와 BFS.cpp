#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, V;
int mat[1001][1001];
int check[1001];

class edge{
public:
	int start;
	int end;
};

vector<edge> arr;

void DFS(int start) {
	cout << start << " ";
	check[start] = 1;
	for (int i = 1; i <=N; i++) {
		if (check[i] == 1 || mat[start][i] == 0)
			continue;
		DFS(i);
	}
}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	check[node] = 0;
	while (!q.empty()) {
		int nextNode = q.front();
		cout << nextNode << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0 || mat[nextNode][i] == 0)
				continue;
			q.push(i);
			check[i] = 0;
		}
	}
} 

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {    //간선의 개수만큼 서로 이어줄 x와 y노드를 입력받습니다.
		int x, y;
		cin >> x >> y;
		mat[x][y] = mat[y][x] = 1;    //인접행렬 표시
	}

	DFS(V);
	cout << endl;
	BFS(V);

}