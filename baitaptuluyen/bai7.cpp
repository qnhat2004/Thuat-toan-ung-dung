#include <bits/stdc++.h>
using namespace std;

/*  
* Tu tuong chinh: 
* Goi dp[i]: so day con ket thuc tai s[i]
* Goi cnt = 1: tong so chuoi con rieng biet
* Voi moi vi tri i >= 1, xet cac vi tri j < i: dp[i] = 1, dp[i] += dp[j]:
* 	- Neu s[i] == s[j], dp[i] += dp[j], dp[i] -= 1, break
* 	- Cuoi cung, cong dp[i] vao bien cnt
* 	- Ket qua la cnt 
* Vi du: s = "baca"
* 	dp[0]: b  1																	cnt: [b] = 1
* 	dp[1]: a  s[1] != s[0] => dp[1] = 1 + 1 = 2									cnt: [b, a, ba] = 1 + 2 = 3
* 	dp[2]: c  s[2] != s[1], s[2] != s[0] => dp[2] = 1 + 2 + 1 = 4				cnt: [b, a, ba, c, bc, ac, bac] = 3 + 3 = 6
* 	dp[3]: a  s[3] != s[2], s[3] == s1 => dp[3] = 1 + 4 + 2 - 1 = 6				cnt: [b, a, ba, c, bc, ac, bac, aca, ca, bca] = 6 + 7 = 13 
*/

/*
Cach hieu khac:
- Voi moi vi tri j nho hon i, dp[i] duoc cong them dp[j]. Vi moi chuoi con ket thuc tai j co the duoc noi them s[i] tao thanh chuoi con ket thuc tai i
- Neu s[i] == s[j], ta se giam di 1 so chuoi con vi chuoi con ket thuc tai i va j giong nhau
*/

#define ll long long

ll mod = 1e9+7, dp[1005], cnt = 1ll; // dp[i] so luong chuoi con rieng biet ket thuc tai vi tri i, khoi tao bang 1, cnt: tong so chuoi con rieng biet
string s;

int main() {
	cin >> s;	
	ll cnt = 1;
	dp[0] = 1;
	for (int i = 1; i < s.length(); i++) {
		dp[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			dp[i] = (dp[i] % mod + dp[j] % mod) % mod;
			if (s[i] == s[j]) {
				dp[i]--;
				break;
			}
		}
		cnt = (cnt % mod + dp[i] % mod) % mod; 		
	}
	cout << cnt << endl;
	return 0;
}
