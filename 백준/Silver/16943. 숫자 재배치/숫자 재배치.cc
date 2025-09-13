#include <iostream>
#include <vector>
#include <string>

bool selected[11];
std::vector<char> arr(11);
std::vector<char> vec;
std::string A, B;
int Bnum, len, max = -1;

void dfs(int cnt) {
	if (cnt == len) {
		if (arr[0] == '0') {
			return;
		}

		std::string tmp;
		for (auto& c : arr) {
			tmp += c;
		}

		int x = std::stoi(tmp);

		if (Bnum > x) {
			max = x > max ? x : max;
		}
		return;
	}

	for (int i = 0; i < len; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = vec[i];
			dfs(cnt + 1);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> A >> B;
	
	for (auto& c : A) {
		vec.push_back(c);
	}

	Bnum = std::stoi(B);
	len = A.length();
	dfs(0);

	std::cout << max;
}