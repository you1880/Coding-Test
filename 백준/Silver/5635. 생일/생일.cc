#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
	std::string name;
	int day;
	int month;
	int year;

	Student(std::string n, int d, int m, int y)
		: name(n), day(d), month(m), year(y) {}
};

bool compare(Student& st1, Student& st2) {
	if (st1.year == st2.year) {
		if (st1.month == st2.month) {
			return st1.day < st2.day;
		}
		return st1.month < st2.month;
	}
	return st1.year < st2.year;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Student> st;
	std::string name;
	int n, day, mon, year;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> name >> day >> mon >> year;

		st.push_back(Student(name, day, mon, year));
	}

	std::sort(st.begin(), st.end(), compare);

	std::cout << st[st.size() - 1].name << "\n" << st[0].name;
}