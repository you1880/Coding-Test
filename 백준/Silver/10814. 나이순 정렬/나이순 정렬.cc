#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Member {
	private:
		int age;
		std::string name;

	public:
		Member(int _age, std::string _name)
			: age(_age), name(_name) {}

		void print() {
			std::cout << age << " " << name << "\n";
		}

		~Member() {}

		friend bool compare(Member m1, Member m2);
};

bool compare(Member m1, Member m2) {
	return m1.age < m2.age;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Member> vec;
	std::string _name;
	int N, _age;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> _age >> _name;
		vec.push_back(Member(_age, _name));
	}

	std::stable_sort(vec.begin(), vec.end(), compare);

	for (auto& m : vec) {
		m.print();
	}
}