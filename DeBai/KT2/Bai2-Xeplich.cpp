#include <bits/stdc++.h>
using namespace std;

struct kh {
	int batdau, ketthuc, tienthue;
	void input() {
		cin >> batdau >> ketthuc >> tienthue;
	}
};

int n;
vector<kh> a(1000);
int dp[1000][1000];

int gen(int k, int last) {
	if (k == n) {
		return 0;
	}
	if (dp[k][last] != -1) {
		return dp[k][last];
	}	
	return dp[k][last] = max(gen(k+1, last), ((a[k].batdau >= last) ? (gen(k+1, a[k].ketthuc) + a[k].tienthue) : 0));
}

int main() {
	cout << "Nhap so luong khach hang: ";
	cin >> n;
	cout << "Thoi gian bat dau, ket thuc, tien thue\n";
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin khach hang " << i << ": ";
		a[i].input();
	}	
	sort(a.begin(), a.begin() + n, [](kh &a, kh &b) {
		return a.ketthuc < b.ketthuc;
	});
	memset(dp, -1, sizeof(dp));
	cout << "Tong tien thue lon nhat co the nhan duoc: " << gen(0, 0); // sua gen(0, -1) ve gen(0, 0) vi ta su dung dp[k][last] de luu, ma last = -1 -> index khong hop le
	return 0;
}
