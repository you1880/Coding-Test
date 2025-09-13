#include <iostream>
#include <cmath>
#include <algorithm>

int func(int x1, int y1, int r1, int x2, int y2, int r2);

int main() {
	int T;
	int x1, y1, r1, x2, y2, r2;

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int result = func(x1, y1, r1, x2, y2, r2);
		std::cout << result << std::endl;
	}
}

int func(int x1, int y1, int r1, int x2, int y2, int r2) {
	double dis = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double sub = r1 > r2 ? r1 - r2 : r2 - r1;
	
	if (dis == 0 && r1 == r2)
		return -1;
	else if (dis < r1 + r2 && dis > sub)
		return 2;
	else if (dis == r1 + r2 || dis == sub)
		return 1;
	else
		return 0;
}