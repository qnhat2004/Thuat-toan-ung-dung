#include <iostream>
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

int z = INF, a[N] = { 0 }, dem = 0, dem1 = 0;  // a[0] -> a[1] -> ... -> a[N-1] -> a[0]
bool b[N] = { false };

//void khoitao() {
//	for (int i = 0; i < N; i++) 
//		for (int j = 0; j < N; j++) c[i][j] = rand() % 100;
//		a[i]
//}

void induongdi(int d) {
	if (d >= z) return;
    dem++;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " --> ";
    }
    cout << "0";  // Tr? v? d?nh xu?t ph�t
    d += c[a[N-1]][0];
    cout << " | Do dai = " << d << endl;
    z = min(d, z);
}

// T�m d?nh a[k]
void tham(int k, int d) {
    dem1++;
    if (k == N) {
        induongdi(d);
        return;
    }
    for (int i = 1; i < N; i++) {  // B? qua d?nh 0 v� d� xu?t ph�t t? d�
        if (!b[i]) {
            b[i] = true;
            a[k] = i;
            if (d + c[a[k-1]][i] + (N-k) < z)	// Cat nhanh, da di qua k dinh, con (N-k) dinh, gia su do dai nho nhat = 1 -> gia su duong di ngan nhat la 1 * (N-k) = (N-k)
            	tham(k+1, d + c[a[k-1]][i]);
            b[i] = false;
        }
    }
}

int main() {
    b[0] = true;  // ��nh d?u d?nh 0 l� noi xu?t ph�t
    tham(1, 0);   // B?t d?u t? d?nh 1 v� chi ph� ban d?u l� 0
    cout << "Duong di ngan nhat co do dai = " << z << endl;
    cout << "So duong di xem xet: " << dem << endl;
    cout << "So lan goi ham tham: " << dem1 << endl;
    return 0;
}

