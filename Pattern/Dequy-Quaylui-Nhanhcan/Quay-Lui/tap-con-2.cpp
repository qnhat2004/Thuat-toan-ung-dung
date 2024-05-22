#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int a[MAX], n, m, cnt = 0;

void print() {
	cout << "Cau hinh " << ++cnt << ": ";
    for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
}
bool dk1() {
	int chan = 0, le = 0;
	for (int i = 1; i <= n; i++)
		(a[i] % 2 == 0) ? chan++ : le++;
	return chan > le;
}
bool dk2() {
	for (int i = 1; i <= n; i++)
		if (a[i] % 5 == 0) return true;
	return false;
}
bool dk3() {
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++)
			if (8 == (a[i] * a[j])) return true;
	}	
	return false;
}
bool dk4() {
	int d = 0;
	for (int i = 1; i <= n; i++)
		if (13 < a[i]) cnt++;
	return cnt > 3;
}
// Chon n phan tu tu tap [1, m]
void gen(int k) {
	if (k > n) { 
		if (dk1() && dk2() && dk3() && dk4()) print();
		return; 
	}
	for (int i = a[k-1] + 1; i <= m-n+k; i++) {
		a[k] = i; gen(k+1);
	}
}
int main()
{
	cout << "Chon n so tu m so nguyen duong dau tien\n";
	cout << "Nhap n, m: ";
    cin >> n >> m;
    a[0] = 0;
    gen(1);
    return 0;
}
