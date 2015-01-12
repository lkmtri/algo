#include <iostream>
#include <cstdio>

using namespace std;

int a[100];
int n;

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void quick_sort(int b[100], int l, int r) {
	if (r > l) {
		int x = b[r];
		int i = l - 1;
		for (int j = l; j < r; j++) {
			if (b[j] < x) {
				i++;
				swap(b[i], b[j]);
			}
		}
		swap(b[r], b[i + 1]);
		quick_sort(b, l, i);
		quick_sort(b, i + 2, r); 
	}
}

int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	print();

	quick_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	cout << endl;
}
