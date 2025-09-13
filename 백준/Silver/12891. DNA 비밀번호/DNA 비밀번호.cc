#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int S, P, cnt = 0;
	int arr[4] = { 0, };
	std::map<char, int> sub = { {'A', 0}, {'C', 0}, {'G', 0}, {'T',0} };
	std::string str;
	std::cin >> S >> P >> str;

	for (int i = 0; i < 4; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < P; i++) {
		sub[str[i]]++;
	}
	
	if (sub['A'] >= arr[0] && sub['C'] >= arr[1] && sub['G'] >= arr[2] && sub['T'] >= arr[3]) {
		cnt++;
	}

	for (int i = P; i < S; i++) {
		sub[str[i - P]]--;
		sub[str[i]]++;

		if (sub['A'] >= arr[0] && sub['C'] >= arr[1] && sub['G'] >= arr[2] && sub['T'] >= arr[3]) {
			cnt++;
		}
	}
	std::cout << cnt;
}