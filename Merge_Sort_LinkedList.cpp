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

void combine(int s[100], int a, int q, int r) {
	int x = q - a + 1;
	int y = r - q;
	int b[100], c[100];
	for (int i = 0; i < x; i++) {
		b[i] = s[a + i];
	}

	for (int i = 0; i < y; i++) {
		c[i] = s[q + 1 + i];
	}
	b[x] = 1000007;
	c[y] = 1000007;
	int d = 0, e = 0;
	for (int i = 0; i <= r - a; i++) {
		if (b[d] < c[e]) {
			s[a + i] = b[d];
			d++;
		} else {
			s[a + i] = c[e];
			e++;
		}
	}
}

void merge_sort(int b[100], int l, int r) {
	if (r > l) {
		int x = (l + r) / 2;
		merge_sort(b, l, x);
		merge_sort(b, x + 1, r);
		combine(b, l, x, r);
	}
}

int main() {
	freopen("input", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	print();
	
	merge_sort(a, 0, n - 1);
	print();
	cout << endl;
}
