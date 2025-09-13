#include <iostream>
#include <string>

class Node {
	public:
		int data;
		Node* next;

		Node()
			: data(0), next(nullptr) {}
		
		~Node() {}
};

class Queue {
	private:
		Node* head;
		Node* tail;
		int size;
	public:
		Queue()
			: head(nullptr), tail(nullptr), size(0) {}

		~Queue() {}

		void Push(int _x);

		int Pop();

		int Size();

		int Empty();

		int Front();

		int Back();
};

void Queue::Push(int _x) {
	Node* node = new Node;
	node->data = _x;
	size++;

	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = tail->next;
	}
}

int Queue::Pop() {
	if (size == 0)
		return -1;

	size--;
	Node* ptr = head;
	int value = head->data;

	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete head;
	}
	else {
		ptr = ptr->next;
		delete head;
		head = ptr;
	}

	return value;
}

int Queue::Size() {
	return size;
}

int Queue::Empty() {
	if (size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int Queue::Front() {
	if (size == 0) {
		return -1;
	}

	return head->data;
}

int Queue::Back() {
	if (size == 0) {
		return -1;
	}

	return tail->data;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	Queue q;

	std::string str;
	int N, x;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		if (str == "push") {
			std::cin >> x;
			q.Push(x);
		}
		else if (str == "pop") {
			std::cout << q.Pop() << "\n";
		}
		else if (str == "size") {
			std::cout << q.Size() << "\n";
		}
		else if (str == "empty") {
			std::cout << q.Empty() << "\n";
		}
		else if (str == "front") {
			std::cout << q.Front() << "\n";
		}
		else if (str == "back") {
			std::cout << q.Back() << "\n";
		}
	}
}