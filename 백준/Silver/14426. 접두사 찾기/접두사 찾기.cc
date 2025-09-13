#include <iostream>
#include <vector>
#include <algorithm>
#define ALPHA_NUM 26

int getIndex(char ch) {
	return ch - 'a';
}

struct Node {
	Node* children[ALPHA_NUM]; 

	Node()
		: children() {}

	void InsertNode(std::string& str) {
		Node* cur = this;

		for (int i = 0; i < str.length(); i++) {
			int next = getIndex(str[i]);
			if (cur->children[next] == nullptr) {
				cur->children[next] = new Node();
			}

			cur = cur->children[next];
		}
	}

	bool isPrefix(std::string& str) {
		Node* cur = this;

		for (int i = 0; i < str.length(); i++) {
			int next = getIndex(str[i]);

			if (cur->children[next] == nullptr) {
				return false;
			}

			cur = cur->children[next];
		}

		return true;
	}
};

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::string str;
	Node* root = new Node();
	int N, M, res = 0;
	std::cin >> N >> M;

	std::vector<std::string> strs(N);
	for (int i = 0; i < N; i++) {
		std::cin >> strs[i];
	}

	std::sort(strs.begin(), strs.end());
	for (auto& e : strs) {
		root->InsertNode(e);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> str;

		if (root->isPrefix(str)) {
			res++;
		}
	}

	std::cout << res;
}