#include <bits/stdc++.h>
using namespace std;

int k, a[100], cnt = 0, ready[100];

void print(int sz)
{
	cout << cnt << ": ";
	cout << a[0];
	for (int i = 1; i < sz; i++)
		cout << "+" << a[i];
	cout << endl;
}

void gen(int cur, int sz, int last = 1e6)
{
	if (cur == 0)
	{
		if (sz > 1)
		{
			cnt++;
			// print(sz);
		}
		return;
	}
	for (int i = min(cur, last); i >= 1; i--)
	{
		if (binary_search(a, a + sz, i) || ready[i])
		{
			continue;
		}
		last = i;
		a[sz] = i;
		ready[i] = 1;
		gen(cur - i, sz + 1, i);
		ready[i] = 0;
	}
}

int main()
{
	cout << "Nhap k = ";
	cin >> k;
	gen(k, 0);
	cout << "Co tat ca " << cnt << " cach phan tich.";
	return 0;
}
