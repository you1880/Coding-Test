#include <iostream>
#define MAX 21

char arr[MAX][MAX] = { 0, };
int alph[26] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int R, C, ans;

void dfs(int x, int y, int cnt) {
	ans = cnt > ans ? cnt : ans;
	alph[arr[x][y] - 'A'] = 1;

	for (int i = 0; i < 4; i++) {
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (_x < 0 || _x >= R || _y < 0 || _y >= C) {
			continue;
		}

		if (alph[arr[_x][_y] - 'A'] == 0) {
			dfs(_x, _y, cnt + 1);
			alph[arr[_x][_y] - 'A'] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> arr[i][j];
		}
	}

	alph[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	std::cout << ans;
}