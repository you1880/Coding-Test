#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Lect {
	int num;
	int start;
	int end;

	Lect(int n, int s, int e)
		: num(n), start(s), end(e) {}
};

struct compare {
	bool operator()(Lect& L1, Lect& L2) {
		if (L1.start == L2.start) {
			return L1.end > L2.end;
		}
		return L1.start > L2.start;
	}
};

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::vector<Lect> lects;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N, no, start, end;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> no >> start >> end;

		lects.push_back({ no, start, end });
	}

	std::sort(lects.begin(), lects.end(), [](Lect& L1, Lect& L2) {
		if (L1.start == L2.start) {
			return L1.end < L2.end;
		}
		return L1.start < L2.start;
	});

	pq.push(lects[0].end);

	for (int i = 1; i < lects.size(); i++) {
		pq.push(lects[i].end);
		if (pq.top() <= lects[i].start) {
			pq.pop();
		}
	}
	std::cout << pq.size();
}