#include <iostream>
#include <vector>
#include <algorithm>

struct Data {
	int cls;
	std::vector<int> scores;

	Data(int c, std::vector<int> sc)
		: cls(c), scores(sc) {}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Data> vec;
	int N, n, max, min, gap = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> n;
		std::vector<int> tmp(n);

		for (int j = 0; j < n; j++) {
			std::cin >> tmp[j];
		}

		std::sort(tmp.begin(), tmp.end(), std::greater<int>());
		vec.push_back(Data(i + 1, tmp));
	}

	for (int i = 0; i < vec.size(); i++) {
		gap = 0;
		max = vec[i].scores[0], min = vec[i].scores[vec[i].scores.size() - 1];

		for (int j = 1; j < vec[i].scores.size(); j++) {
			gap = vec[i].scores[j - 1] - vec[i].scores[j] > gap ? vec[i].scores[j - 1] - vec[i].scores[j] : gap;
		}
		std::cout << "Class " << vec[i].cls << "\n";
		std::cout << "Max " << max << ", Min " << min << ", Largest gap " << gap << "\n";
	}
}