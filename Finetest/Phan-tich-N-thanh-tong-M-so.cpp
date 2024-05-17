#include<bits/stdc++.h>
using namespace std;

int m, n;
int tmp[100];

void print() {
	cout << n << " = " << tmp[0];
	for (int i = 1; i < m; i++)
		cout << "+" << tmp[i];
	cout << endl;
}
void gen(int i, int sum) {
	if (i == m) {
		if (sum == n) {
			print();
		}
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (sum + j > n) continue;
		tmp[i] = j;
		gen(i+1, sum+j); 
	}
}
int main(){
	cout << "Nhap n = "; cin >> n;
	cout << "Nhap m = "; cin >> m;
	gen(0, 0);	
	return 0;
}
