#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, num;
	std::map<int, int> dic;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		auto itr = dic.find(num);
		if (itr == dic.end()) {
			dic.insert({ num, 1 });
		}
		else {
			itr->second++;
		}
	}
	
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> num;
		auto itr = dic.find(num);
		if (itr == dic.end()) {
			std::cout << "0 ";
		}
		else {
			std::cout << itr->second << " ";
		}
	}
}