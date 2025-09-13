#include <iostream>
#include <vector>
#include <queue>
#define MAX 21

std::vector<std::vector<int>> map(MAX, std::vector<int>(MAX, 0));
std::vector<int> dice = { 6, 5, 1, 2, 4, 3 }; 
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int N, M, K, curR = 1, curC = 1;
int dir = 0, res = 0;

void checkDir() {
	if (dir == 0 && curC == M) {
		dir = 2;
	}
	else if (dir == 1 && curR == N) {
		dir = 3;
	}
	else if (dir == 2 && curC == 1) {
		dir = 0;
	}
	else if (dir == 3 && curR == 1) {
		dir = 1;
	}
}

void Move() {
	std::vector<int> tmpDice = dice;
	if (dir == 0) {
		tmpDice[0] = dice[5];
		tmpDice[2] = dice[4];
		tmpDice[4] = dice[0];
		tmpDice[5] = dice[2];
	}
	else if (dir == 1) {
		tmpDice[0] = dice[1];
		tmpDice[1] = dice[2];
		tmpDice[2] = dice[3];
		tmpDice[3] = dice[0];
	}
	else if (dir == 2) {
		tmpDice[0] = dice[4];
		tmpDice[2] = dice[5];
		tmpDice[4] = dice[2];
		tmpDice[5] = dice[0];
	}
	else if (dir == 3) {
		tmpDice[0] = dice[3];
		tmpDice[1] = dice[0];
		tmpDice[2] = dice[1];
		tmpDice[3] = dice[2];
	}

	dice = tmpDice;
}

int getPoint() {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));
	int sum = map[curR][curC];

	visited[curR][curC] = true;
	q.push({ curR, curC });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr <= 0 || nc <= 0 || nr > N || nc > M || map[nr][nc] != map[curR][curC] || visited[nr][nc]) {
				continue;
			}

			q.push({ nr, nc });
			visited[nr][nc] = true;
			sum += map[nr][nc];
		}
	}

	return sum;
}

void RotateDir() {
	int bottom = dice[0];
	if (bottom > map[curR][curC]) {
		dir = dir + 1 > 3 ? 0 : dir + 1;
	}
	else if (bottom < map[curR][curC]) {
		dir = dir - 1 < 0 ? 3 : dir - 1;
	}
}

void Sol() {
	checkDir();
	Move();

	curR = curR + dr[dir];
	curC = curC + dc[dir];

	res += getPoint();

	RotateDir();
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		Sol();
	}
	std::cout << res;
}