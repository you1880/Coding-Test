#include <iostream>
#include <vector>
#define MAX 51

struct Fireball {
	int row;
	int col;
	int mass;
	int speed;
	int dir;

	Fireball(int r, int c, int m, int s, int d)
		: row(r), col(c), mass(m), speed(s), dir(d) {}
};

struct Space {
	int masses;
	int speed;
	std::vector<int> dirs;

	Space() {
		masses = 0;
		speed = 0;
		dirs = std::vector<int>();
	}
};

std::vector<std::vector<Space>> map(MAX, std::vector<Space>(MAX, Space()));
std::vector<Fireball> fireballs;
int N, M, K;

void ballmove() {
	for (auto& ball : fireballs) {
		int dir = ball.dir;
		int speed = ball.speed % N;

		switch (dir) {
			case 0:
				ball.row = ball.row - speed < 1 ? (N - speed) + ball.row : ball.row - speed;
				break;
			case 1:
				ball.row = ball.row - speed < 1 ? (N - speed) + ball.row : ball.row - speed;
				ball.col = ball.col + speed > N ? (ball.col + speed) % N : ball.col + speed;
				break;
			case 2:
				ball.col = ball.col + speed > N ? (ball.col + speed) % N : ball.col + speed;
				break;
			case 3:
				ball.row = ball.row + speed > N ? (ball.row + speed) % N : ball.row + speed;
				ball.col = ball.col + speed > N ? (ball.col + speed) % N : ball.col + speed;
				break;
			case 4:
				ball.row = ball.row + speed > N ? (ball.row + speed) % N : ball.row + speed;
				break;
			case 5:
				ball.row = ball.row + speed > N ? (ball.row + speed) % N : ball.row + speed;
				ball.col = ball.col - speed < 1 ? (N - speed) + ball.col : ball.col - speed;
				break;
			case 6:
				ball.col = ball.col - speed < 1 ? (N - speed) + ball.col : ball.col - speed;
				break;
			case 7:
				ball.row = ball.row - speed < 1 ? (N - speed) + ball.row : ball.row - speed;
				ball.col = ball.col - speed < 1 ? (N - speed) + ball.col : ball.col - speed;
				break;
		}

		int nr = ball.row, nc = ball.col;

		map[nr][nc].masses += ball.mass;
		map[nr][nc].speed += ball.speed;
		map[nr][nc].dirs.push_back(dir);
	}
	fireballs.clear();
}

void balldivide() {
	std::vector<Fireball> tmp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].dirs.size() == 1) {
				tmp.push_back(Fireball(i, j, map[i][j].masses, map[i][j].speed, map[i][j].dirs[0]));
			}
			else if (map[i][j].dirs.size() >= 2) {
				int mass = map[i][j].masses / 5;
				if (mass > 0) {
					int size = map[i][j].dirs.size();
					int speed = map[i][j].speed / size, init = 0, d = map[i][j].dirs[0];

					for (int t = 1; t < size; t++) {
						if (d % 2 != map[i][j].dirs[t] % 2) {
							init = 1;
							break;
						}
					}

					for (int f = 0; f < 4; f++) {
						tmp.push_back(Fireball(i, j, mass, speed, init));
						init += 2;
					}
				}
			}

			map[i][j].masses = 0;
			map[i][j].speed = 0;
			map[i][j].dirs.clear();
		}
	}

	fireballs = tmp;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int r, c, m, s, d, count = 0;
	std::cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		std::cin >> r >> c >> m >> s >> d;
		
		Fireball fire = Fireball(r, c, m, s, d);
		fireballs.push_back(fire);
	}

	for (int i = 0; i < K; i++) {
		ballmove();
		balldivide();
		ballmove();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			count += map[i][j].masses;
		}
	}

	std::cout << count;
}