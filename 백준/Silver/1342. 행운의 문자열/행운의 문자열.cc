#include <iostream>
#include <vector>

int alph[26];
std::vector<char> arr(10);
int length = 0, res = 0;

void func(int cnt) {
	if (cnt == length) {
		res++;
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (alph[i] == 0) {
			continue;
		}

		if (cnt > 0 && (arr[cnt - 1] - 'a') == i) {
			continue;
		}
		arr[cnt] = (char)(i + 'a');
		alph[i]--;
		func(cnt + 1);
		alph[i]++;
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::string str;
	std::cin >> str;

	for (auto& ch : str) {
		alph[ch - 'a']++;
	}

	length = str.length();
	
	func(0);
	std::cout << res;
}