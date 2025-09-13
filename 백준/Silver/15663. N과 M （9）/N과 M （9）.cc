#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
bool visited[9];
int arr[9];
int N, M;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";

		return;
	}

	int tmp = 0;

	for (int i = 0; i < N; i++) {	
		if (!visited[i] && tmp != vec[i]) {
			tmp = vec[i];
			visited[i] = true;
			arr[cnt] = vec[i];

			dfs(cnt + 1);

			visited[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int x;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> x;
		vec.push_back(x);
	}

	std::sort(vec.begin(), vec.end());

	dfs(0);
}