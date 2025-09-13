#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX 21

struct Fish {
	int r;
	int c;
	int dist;
};

struct Compare {
	bool operator() (const Fish& f1, const Fish& f2) const {
		if (f1.dist == f2.dist) {
			if (f1.r == f2.r) {
				return f1.c < f2.c;
			}

			return f1.r < f2.r;
		}

		return f1.dist < f2.dist;
	}
};

std::vector<std::vector<int>> vec(MAX, std::vector<int>(MAX));
std::vector<std::pair<int, int>> fishes;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int N, t = 0;
int s_size = 2, ate = 0, s_r, s_c;

int bfs() {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> dist(N, std::vector<int>(N, 0));
	std::set<Fish, Compare> fish;

	q.push({ s_r, s_c });
	dist[s_r][s_c] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a < 0 || b < 0 || a >= N || b >= N || vec[a][b] > s_size || dist[a][b]) {
				continue;
			}

			dist[a][b] = dist[x][y] + 1;
			q.push({ a,b });

			if (vec[a][b] != 0 && s_size > vec[a][b]) {
				fish.insert({ a, b, dist[a][b] });
			}
		}
	}

	if (fish.empty()) {
		return 0;
	}
	else {
		vec[s_r][s_c] = 0;

		s_r = fish.begin()->r;
		s_c = fish.begin()->c;
		vec[s_r][s_c] = 9;
		
		return fish.begin()->dist - 1;
	}	

	

}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> vec[i][j];

			if (vec[i][j] == 9) {
				s_r = i;
				s_c = j;
			}
		}
	}

	while (true) {
		int d = bfs();

		if (d == 0) {
			break;
		}
		else {
			t += d;
			ate++;

			if (s_size == ate) {
				s_size++;
				ate = 0;
			}
		}
	}

	std::cout << t;
}