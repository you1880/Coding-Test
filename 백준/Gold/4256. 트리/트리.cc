#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
	int num;
	Node* left;
	Node* right;

	Node(int n) {
		num = n;
		left = nullptr;
		right = nullptr;
	}
};

int idx = 0;

Node* build_tree(std::vector<int>& pre, std::vector<int>& in, int left, int right) {
	if (left > right) {
		return nullptr;
	}

	int root_num = pre[idx++];
	Node* root = new Node(root_num);

	int sub_idx = std::find(in.begin(), in.end(), root_num) - in.begin();

	root->left = build_tree(pre, in, left, sub_idx - 1);
	root->right = build_tree(pre, in, sub_idx + 1, right);

	return root;
}

void post_order(Node* root) {
	if (root->left != nullptr) {
		post_order(root->left);
	}

	if (root->right != nullptr) {
		post_order(root->right);
	}

	std::cout << root->num << " ";
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		std::vector<int> preorder(N);
		std::vector<int> inorder(N);

		for (int i = 0; i < N; i++) {
			std::cin >> preorder[i];
		}

		for (int i = 0; i < N; i++) {
			std::cin >> inorder[i];
		}

		idx = 0;
		Node* root = build_tree(preorder, inorder, 0, inorder.size() - 1);

		post_order(root);
		std::cout << "\n";
	}
}