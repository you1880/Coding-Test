#include <iostream>
#include <vector>

int N, S, res = 0;
std::vector<int> nums;
int arr[21];
bool selected[21];

void func(int idx, int cnt, int n) {
	if (cnt == n) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += arr[i];
		}

		if (S == tmp) {
			res++;
		}

		return;
	}

	for (int i = idx; i < N; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = nums[i];
			func(i, cnt + 1, n);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int x;
		std::cin >> x;

		nums.push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		func(0, 0, i);
	}
	
	std::cout << res;
}