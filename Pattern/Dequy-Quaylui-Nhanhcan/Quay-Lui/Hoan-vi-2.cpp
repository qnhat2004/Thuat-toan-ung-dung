#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int a[N+1], b[N+1], cnt = 0; // Mang b danh dau

int tong() {
	return a[0]+a[1]-a[2]+a[3]-a[4]+a[5]-a[6]+a[7]-a[8];		
}
void print() {
	cout << ++cnt << ": ";
	cout << a[0];
	for (int i = 1; i < N; i++) cout << "+-"[i%2==0] << a[i];
	cout << endl;
}
void gen(int k) {
	if (k >= N) {
		if (23 == tong())
			print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (b[i] == 0) {
			b[i] = 1;
			a[k] = i;
			gen(k+1);
			b[i] = 0;
		}
	}
}
int main()
{
	gen(0);
    return 0;
}
