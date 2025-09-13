#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>

struct Data {
	char alph = '0';
	long long w = 0;
};

int compare(Data& d1, Data& d2) {
	return d1.w > d2.w;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::string str;
	std::vector<std::string> strs;
	std::unordered_map<char, Data> dict;
	std::unordered_map<char, int> trans;
	int N, sum = 0, init = 9;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		strs.push_back(str);

		int len = str.length();
		for (int j = 0; j < len; j++) {
			dict[str[j]].alph = str[j];
			dict[str[j]].w += static_cast<long long>(std::pow(10, len - j));
		}
	}

	std::vector<Data> vec;
	for (const auto& e : dict) {
		vec.push_back(e.second);
	}
	
	std::sort(vec.begin(), vec.end(), compare);
	for (const auto& e : vec) {
		trans[e.alph] = init--;
	}

	for (int i = 0; i < N; i++) {
		int m = 1;
		for (int j = strs[i].length() - 1; j >= 0; j--) {
			sum += trans[strs[i][j]] * m;
			m *= 10;
		}
	}

	std::cout << sum;
}