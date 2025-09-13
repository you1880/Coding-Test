#include <iostream>
#include <vector>
#include <algorithm>

class Point {
	private:
		int x;
		int y;

	public:
		Point(int _x, int _y)
			: x(_x), y(_y) {}

		void print() {
			std::cout << x << " " << y << "\n";
		}

		~Point() {}

		friend bool compare(Point p1, Point p2);
};

bool compare(Point p1, Point p2) {
	if (p1.x == p2.x)
		return p1.y < p2.y;

	return p1.x < p2.x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Point> vec;
	int N, x, y;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;
		vec.push_back(Point(x, y));
	}

	std::sort(vec.begin(), vec.end(), compare);

	for (auto p : vec) {
		p.print();
	}
}