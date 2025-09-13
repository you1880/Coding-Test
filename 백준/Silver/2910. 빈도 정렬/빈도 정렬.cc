#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct Data {
	int number;
	int freq;
	int idx;

	Data()
		: number(0), freq(0), idx(0) {}

	Data(int n, int f, int i)
		: number(n), freq(f), idx(i) {}
};

bool compare(Data& d1, Data& d2) {
	if (d1.freq == d2.freq) {
		return d1.idx < d2.idx;
	}
	return d1.freq > d2.freq;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<int, Data> dict;
	int N, C, x;
	std::cin >> N >> C;

	for (int i = 0; i < N; i++) {
		std::cin >> x;

		if (dict.find(x) == dict.end()) {
			dict[x] = Data(x, 1, i);
		}
		else {
			dict[x].freq++;
		}
	}

	std::vector<Data> vec;
	for (const auto& e : dict) {
		vec.push_back(Data(e.second.number, e.second.freq, e.second.idx));
	}
	std::sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].freq; j++) {
			std::cout << vec[i].number << " ";
		}
	}
}