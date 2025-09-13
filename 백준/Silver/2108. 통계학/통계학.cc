#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> vec;
	std::vector<std::pair<int, int>> rdx(8001);
	int N, x, min = 0, max = 0, sum = 0, md;
	double avg;
	std::cin >> N;

	for (int i = -4000; i <= 4000; i++) {
		rdx[i + 4000].first = i;
	}
	
	for (int i = 0; i < N; i++) {
		std::cin >> x;
		vec.push_back(x);
		
		rdx[x + 4000].second++;
		sum += x;
		max = x > max ? x : max;
		min = min > x ? x : min;
	}

	rdx.erase(std::remove_if(rdx.begin(), rdx.end(), [](std::pair<int, int> p) {return p.second == 0; }), rdx.end());
	std::sort(rdx.begin(), rdx.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {return p1.second > p2.second; });
	std::sort(vec.begin(), vec.end());

	md = rdx.size() > 1 ? rdx[0].second == rdx[1].second ? rdx[1].first : rdx[0].first : rdx[0].first;
	avg = std::round(static_cast<double>(sum) / N);
	avg = avg == -0 ? 0 : avg;

	std::cout << avg << "\n";
	std::cout << vec[N / 2] << "\n" << md << "\n" << vec[vec.size() - 1] - vec[0];
}