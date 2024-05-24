#include <bits/stdc++.h>
using namespace std;

const int INF = 1e4;
const int N = 8;

int c[N][N] = {
	{ 	0, 		2, 		3, 		1, 	 	INF, 	INF, 	INF, 	INF },
	{ 	2, 		0, 		6, 		INF, 	5, 		1, 		INF, 	INF },
	{ 	3, 		6, 		0, 		1, 	 	INF, 	1, 		8, 		INF },
	{ 	1, 		INF, 	1, 		0, 	 	INF, 	INF, 	7, 		INF },
	{ 	INF, 	5, 		INF, 	INF, 	0, 	    4, 	    INF, 	1 },
	{ 	INF, 	1, 		1, 		INF, 	4, 		0, 		5, 		7 },
	{ 	INF, 	INF, 	8, 		7, 		INF, 	5, 	    0, 	    5 },
	{ 	INF, 	INF, 	INF, 	INF, 	1, 	    7, 	    5, 	    0 },
};

int min_length = INF, cnt = 0, duong = 0, lap = 0, a[N] = { 0 }; // a[0] -> a[1] -> ... -> a[N-1] -> a[0]
bool ready[N] = { false };	// Danh dau cac diem da tham

void induongdi(int d) {
	duong++;	// So duong di xem xet
	cout << "Duong di thu " << ++cnt << ": " << endl;
	for (int i = 0; i < N-1; i++) {
		cout << a[i] << " --(" << c[a[i]][a[i+1]] << ")--> ";
	}
	cout << a[N-1] << " --(" << c[a[N-1]][0] << ")--> 0";  // 0: Tro ve dinh xuat phat
	cout << " | Do dai = " << d << endl;
	min_length = min(min_length, d);
}

void tham(int k, int d) {
	lap++;	// So lan goi ham tham
	if (k == N) {
		d += c[a[N-1]][0]; 	// a[k-1]: dinh da tham truoc do
		if (d < min_length) {
			cout << "Phat hien duong di moi toi uu hon: ";
			induongdi(d);
		}
		return;
	}
	for (int i = 1; i < N; i++) {
		if (!ready[i]) { 
			if (d + c[a[k-1]][i] + (N-k) < min_length) {	// 	Cat nhanh, con (N-k) dinh chua xet. Gia su do dai moi canh = 1 -> do dai toi thieu de di het (N-k) dinh: 1 * (N-k) = N-k	
				a[k] = i;	// Tai lan tham thu k, tham dinh i
				ready[i] = true;
				tham(k+1, d + c[a[k-1]][i]);
				ready[i] = false;
			}
		}
	}
}

int main() {
	ready[0] = true;	// Danh dau dinh 0 la noi xuat phat
	tham(1, 0);		// Bat dau tu lan lap thu 1 voi chi phi ban dau la 0, "tham(k+1, d + c[a[k-1]][k]);" = 0 + c[a[0]][1] = c[0][1]
	cout << "Duong di ngan nhat co do dai: " << min_length << endl;
	cout << "So duong di xem xet: " << duong << endl;
	cout << "So lan goi ham tham: " << lap << endl;
	return 0;
}
