#include <bits/stdc++.h>
using namespace std;

int m, n, mx = INT_MIN;
int a[1000], b[1000];

map<vector<int>, int> v1, v2;

void print(vector<int> &tmp) {
    for (auto &x : tmp) cout << x << " ";
    cout << endl << endl;
}

void gen(int x[], int n, int i, int sum, vector<int>&tmp, map<vector<int>, int> &v) {
    if (i == n) {
        v[tmp] = sum;
        // print(tmp);
        return;
    }
    gen(x, n, i+1, sum, tmp, v);
    tmp.push_back(x[i]);
    gen(x, n, i+1, sum + x[i], tmp, v);
    tmp.pop_back();
}

int main()
{
    cout << "Nhap m = "; cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "a[" << i+1 << "] = ";
        cin >> a[i]; 
    }
    cout << "Nhap n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i+1 << "] = ";
        cin >> b[i]; 
    }
    vector<int> tmp;
    gen(a, m, 0, 0, tmp, v1);
    gen(b, n, 0, 0, tmp, v2);
    for (auto &x : v1) {
        if (v2.count(x.first)) {
            mx = max(mx, x.second);
        }
    }
    cout << "Day con co tong lon nhat = " << mx;
    return 0;
}