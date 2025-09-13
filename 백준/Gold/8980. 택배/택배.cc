#include <iostream>
#include <vector>
#include <algorithm>

struct Prod {
	int start;
	int end;
	int boxes;

	Prod(int s, int e, int b)
		: start(s), end(e), boxes(b) {}
};

bool compare(Prod p1, Prod p2) {
	if (p1.end < p2.end)
		return true;
	else if (p1.end == p2.end) {
		if (p1.start < p2.start) {
			return true;
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> vec;
	std::vector<Prod> prd;
	int N, C, M, s, e, b;
	int boxes = 0, cur_b = 0;
	std::cin >> N >> C >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> s >> e >> b;

		prd.push_back(Prod(s, e, b));
	}

	std::sort(prd.begin(), prd.end(), compare);

	vec.assign(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int m = 0;

		for (int j = prd[i].start; j < prd[i].end; j++) {
			m = vec[j] > m ? vec[j] : m;
		}
		
		cur_b = prd[i].boxes > C - m ? C - m : prd[i].boxes;
		boxes += cur_b;

		for (int j = prd[i].start; j < prd[i].end; j++) {
			vec[j] += cur_b;
		}
	}
	std::cout << boxes;
}