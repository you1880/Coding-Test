#include <iostream>
#include <algorithm>
#define MAX_HEAP_SIZE 100001

int heap[MAX_HEAP_SIZE];
int heap_idx = 0;

void push(int data) {
	int idx = ++heap_idx;
	heap[idx] = data;

	while ((idx != 1) && (heap[idx] <= heap[idx / 2])) {
		std::swap(heap[idx], heap[idx / 2]);
		idx = idx / 2;
	}
}

int pop() {
	if (heap_idx == 0) {
		return 0;
	}

	int top = heap[1];
	heap[1] = heap[heap_idx--];

	int parent = 1, child;
	while (1) {
		child = parent * 2;
		
		if (child + 1 <= heap_idx && heap[child] > heap[child + 1]) {
			child++;
		}
		if (child > heap_idx || heap[child] > heap[parent]) {
			break;
		}
		std::swap(heap[child], heap[parent]);
		parent = child;
	}

	return top;
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, x;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x;

		if (x == 0) {
			std::cout << pop() << "\n";
		}
		else {
			push(x);
		}
	}
}