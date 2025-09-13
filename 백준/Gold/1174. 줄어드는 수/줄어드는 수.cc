#include <iostream>
#include <vector>
#include <string>

std::vector<char> num = { '9','8','7','6','5','4','3','2','1','0' };
char arr[10];

int N,  num_cnt = 10;
long long res = -1;
bool flag = false;

void sol(int M, int cnt, int idx) {
	if (flag) {
		return;
	}

	if (cnt == M) {
		num_cnt++;

		if (num_cnt == N) {
			std::string tmp = "";
			
			for (int i = 0; i < M; i++) {
				tmp += arr[i];
			}

			res = std::stoll(tmp);
			flag = true;
		}
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (cnt == 0) {
			arr[cnt] = num[i];
			sol(M, cnt + 1, i);
		}
		else {
			if (arr[cnt - 1] > num[i]) {
				arr[cnt] = num[i];
				sol(M, cnt + 1, i);
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	if (N <= 10) {
		std::cout << N - 1;
	}
	else {
		for (int i = 2; i <= 10; i++) {
			sol(i, 0, 0);
		}
        std::cout << res;
	}
}