#include <iostream>
#include <vector>
#include <map>
#include <string>
#define NUM_ALPH 26
int toIndex(char ch) { return ch - 'a'; }

struct TrieNode {
	TrieNode* children[NUM_ALPH];
	bool isEnd;

	TrieNode()
		: children(), isEnd(false) {}

	void InsertNode(std::string& str) {
		TrieNode* cur = this;

		for (int i = 0; i < str.length(); i++) {
			int next = toIndex(str[i]);
			if (cur->children[next] == nullptr) {
				cur->children[next] = new TrieNode();
			}

			cur = cur->children[next];
		}
	}

	bool isPrefix(std::string& str) {
		TrieNode* cur = this;

		for (int i = 0; i < str.length(); i++) {
			int next = toIndex(str[i]);

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

	std::map<std::string, int> dict;
	std::vector<std::string> nicks;
	std::string nickname;
	TrieNode* root = new TrieNode();
	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> nickname;

		nicks.push_back(nickname);
		dict[nickname]++;

		if (dict[nickname] < 2) {
			std::string tmp = "";
			bool flag = true;

			for (auto& ch : nickname) {
				tmp += ch;
				if ((flag = root->isPrefix(tmp)) == false) {
					std::cout << tmp << "\n";
					break;
				}
			}

			if (flag) {
				std::cout << nickname << "\n";
			}
			root->InsertNode(nickname);

		}
		else {
			std::cout << nickname + std::to_string(dict[nickname]) << "\n";
		}
	}
}