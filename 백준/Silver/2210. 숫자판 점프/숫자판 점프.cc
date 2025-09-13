#include <iostream>
#include <set>
#include <string>

std::set<std::string> res;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[5][5];

void dfs(int x, int y, int cnt, std::string str) {
	if (cnt == 6) {
		res.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= 5 || b >= 5) {
			continue;
		}

		dfs(a, b, cnt + 1, str + std::to_string(arr[a][b]));
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::string str = std::to_string(arr[i][j]);
			dfs(i, j, 1, str);
		}
	}

	std::cout << res.size();
}