#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
	int val;
	Node *next;
};

Node *first = new Node();
Node *last = new Node();
int n;

void print() {
	Node *node = first;
	while (node) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}  

void readInput() {
	freopen("input", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &(first->val));
	first->next = NULL;
	Node *node = first;
	for (int i = 1; i < n; i++) {
		Node *newNode = new Node();
		scanf("%d", &(newNode->val));
		newNode->next = NULL;
		node->next = newNode;
		node = newNode;
	}
	last = node;
}

void quick_sort(Node *start, Node *end) {
	if (start->next != end && start != end) {
		int v = end->val;
		Node *node = start->next, *prev = start;
		Node *last = node;
		while (node != end) {
			if (node->val < v) {
				swap(node->val, last->val);
				prev = last;
				last = last->next;
			}
			node = node->next;
		}
		swap(last->val, end->val);
		quick_sort(start, prev);
		quick_sort(last, end);
	}
}

int main() {
	readInput();
	print();
	Node *node = new Node();
	node->val = -1;
	node->next = first;
	quick_sort(node, last);
	print();
}
