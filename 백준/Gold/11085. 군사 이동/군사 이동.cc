#include <iostream>
#include <vector>
#include <algorithm>

struct Data {
	int start;
	int end;
	int width;
};

int root[1001];
std::vector<Data> vec;
int p, w, c, v;

int compare(const Data& d1, const Data& d2) {
	return d1.width > d2.width;
}

int Find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = Find(root[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	root[y] = x;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> p >> w >> c >> v;
	
	for (int i = 0; i < p; i++) {
		root[i] = i;
	}

	for (int i = 0; i < w; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		vec.push_back({ a,b,c });
	}

	std::sort(vec.begin(), vec.end(), compare);

	for (const auto& d : vec) {
		int s = Find(d.start), e = Find(d.end), w = d.width;

		if (s != e) {
			Union(s, e);
		}

		if (Find(c) == Find(v)) {
			std::cout << w;
			return 0;
		}
	}
}