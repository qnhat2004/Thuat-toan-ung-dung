#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, ss;
    cin >> s;
    ss = s;
    reverse(ss.begin(), ss.end());  
    long long len = s.length();
    long long t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if (n / len % 2 == 0) cout << s[n % len]; // Chuoi nguoc
        else cout << ss[n % len]; // Chuoi xuoi
        cout << '\n';
    }
    return 0;
}