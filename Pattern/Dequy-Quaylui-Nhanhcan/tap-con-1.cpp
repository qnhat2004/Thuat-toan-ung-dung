#include <bits/stdc++.h>
using namespace std;

vector<int> tmp;
void print(vector<int> a, int n);
void gen(int n, int a[], int k, int i, int sum) {
    if (tmp.size() == k) { 
        print(tmp, k); 
        cout << "Sum = " << sum << endl; 
        return; 
    }
    if (i == n) return;
    tmp.push_back(a[i]);
    gen(n, a, k, i+1, sum + a[i]);
    tmp.pop_back();
    gen(n, a, k, i+1, sum);
}
void print(vector<int> a, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &i : a) cin >> i;
    gen(n, a, k, 0, 0);
    return 0;
}