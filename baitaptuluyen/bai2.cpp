#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll n;
	cin >> n;
	int cnt = 0;
	for (ll a = 1; a <= n; a++) 
		for (ll b = a; b <= n; b++) {
			ll c2 = a*a + b*b;
			ll c = sqrt(c2);
			if (c*c == c2 && c <= n && a+b+c <= n)
				cnt++;
		}
	cout << cnt;
}

/*
Voi moi cap canh (a, b), no se la tam giac vuong khi ton tai
canh c t/m: a^2 + b^2 = c^2

goi c2 = a^2 + b^2

- Kiem tra xem c2 co phai so chinh phuong khong
- Neu c2 la scp, kiem tra xem co c = sqrt(c2) co nho hon hoac
bang n hay khong
- Neu c <= n, kiem tra xem lieu chu vi 3 canh cua tam giac
co <= n hay khong.

DPT: O(n^2)
*/
