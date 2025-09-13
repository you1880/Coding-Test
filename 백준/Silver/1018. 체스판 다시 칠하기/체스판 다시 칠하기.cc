#include <iostream>
#include <vector>

int check_bw(std::vector<std::string> arr, int x, int y) {
	std::vector<std::string> bw = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" ,"BWBWBWBW","WBWBWBWB" ,"BWBWBWBW","WBWBWBWB" };
	int cnt = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (arr[i][j] != bw[i - x][j - y]) {
				cnt++;
			}
		}
	}
	
	return cnt;
}

int check_wb(std::vector<std::string> arr, int x, int y) {
	std::vector<std::string> wb = { "WBWBWBWB","BWBWBWBW" ,"WBWBWBWB","BWBWBWBW" ,"WBWBWBWB","BWBWBWBW" ,"WBWBWBWB","BWBWBWBW" };

	int cnt = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (arr[i][j] != wb[i - x][j - y]) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, cnt = 10000;
	int bt = 0, wt = 0;
	std::cin >> N >> M;

	std::vector<std::string> arr(N);

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			bt = check_bw(arr, i, j);
			wt = check_wb(arr, i, j);

			int m = std::min(bt, wt);
			cnt = cnt > m ? m : cnt;
		}
	}
	std::cout << cnt;
}