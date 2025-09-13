#include <iostream>
#include <vector>
#include <string>
#define MAX 1000000

std::string X;
std::vector<int> nums;
int arr[8];
bool selected[8];
int len, Xnum, res = MAX;

void dfs(int cnt) {
	if (cnt == len) {
		std::string tmp;

		for (int i = 0; i < len; i++) {
			tmp += std::to_string(arr[i]);
		}

		int x = std::stoi(tmp);
		if (x > Xnum) {
			res = res > x ? x : res;
		}

		return;
	}

	for (int i = 0; i < len; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = nums[i];
			dfs(cnt + 1);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> X;
	for (auto& c : X) {
		nums.push_back(c - '0');
	}

	len = X.length();
	Xnum = std::stoi(X);

	dfs(0);

	res = res == MAX ? 0 : res;
	std::cout << res;
}