#include <iostream>
#include <vector>

std::vector<char> chs = { 'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z' };
std::vector<bool> selected(21, false);
std::vector<char> arr(21);
std::vector<std::vector<char>> substrs;
int N, K, S, ans = 0;

void Sol(int s) {
	int cnt = 0;

	for (auto& substr : substrs) {
		bool check = true;

		for (auto& e : substr) {
			if (!(s & (1 << (e - 'a')))) {
				check = false;
				break;
			}
		}

		if (check) {
			cnt++;
		}
	}

	ans = std::max(ans, cnt);
}

void func(int cnt, int idx) {
	if (cnt == K - 5) {
		int s = S;
		for (int i = 0; i < cnt; i++) {
			s |= (1 << (arr[i] - 'a'));
		}

		Sol(s);
		return;
	}

	for (int i = idx; i < 21; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = chs[i];
			func(cnt + 1, i);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;

		std::string substr = str.substr(4, str.length() - 8);
		std::vector<char> tmp;

		for (auto e : substr) {
			tmp.push_back(e);
		}

		substrs.push_back(tmp);
	}

	if (K < 5) {
		std::cout << "0";
		return 0;
	}

	std::vector<char> ch = { 'a', 'c', 'i', 't', 'n' };
	for (auto e : ch) {
		S |= (1 << (e - 'a'));
	}

	func(0, 0);

	std::cout << ans;
}