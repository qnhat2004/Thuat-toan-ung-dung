#include <bits/stdc++.h>
using namespace std;

// https://byjus.com/pythagorean-triples-formula/

/*
Cong thuc bo 3 Pytago:
a = m^2 - n^2
b = 2mn
c = m^2 + n^2
? Neu (a, b, c) la 3 canh tam giac vuong thi (ka, kb, kc) cung la 3 canh tam giac vuong
? Voi m > n > 0, m va n la 2 so nguyen to cung nhau, m + n la so le
* 2 so nguyen to cung nhau thi UCLN = 1, VD: (3, 4), (5, 12)
-> a + b + c = 2m(m+n) <= N
-> 2m^2 + 2mn <= N
*/

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i < sqrt(n); i++) {
		for (int j = i + 1; j < sqrt(n); j++) {
			if (2*j*j + 2*j*i > n) break; // 2m^2 + 2mn <= N
			if (__gcd(i, j) == 1 && (i + j) % 2 == 1) { // 
				int a = j*j - i*i;
				int b = 2*j*i;
				int c = j*j + i*i;
				int k = 1;
				while(k * (a+b+c) <= n) { 	// (a, b, c) la tam giac vuong -> k(a, b, c) cung la tam giac vuong
					cnt++;
					k++;
				}
			}
		}
	}
	cout << cnt;
}
