#include <bits/stdc++.h>
using namespace std;

#define output(a) for(auto &i : a) cout << i << " "; cout << endl;

struct item {
    int index, giatri, trongluong;
    double dongia;
};

vector<item> items;
vector<int> path1, path2, path3;
int w, n;

int tinhtoan(vector<int> &path, int w, vector<item> &items) {
    int sum = 0, i = 0;
    while (w > 0 && i < n)
    {
        if (w >= items[i].trongluong)
        {
            sum += items[i].giatri;
            w -= items[i].trongluong;
            path.push_back(items[i].index);
        }
        i++;
    }
    return sum;
}

// Sap xep theo gia tri giam dan
int cach1(int w, vector<item> items) {
    sort(items.begin(), items.end(), [](item a, item b) {
        return a.giatri > b.giatri;
    });
    return tinhtoan(path1, w, items);
}

// Sap xep theo trong luong tang dan
int cach2(int w, vector<item> items_) {
    sort(items_.begin(), items_.end(), [](item a, item b) {
        return a.trongluong < b.trongluong;
    });
    return tinhtoan(path2, w, items_);
}

// Sap xep theo don gia giam dan
int cach3(int w, vector<item> items) {
    sort(items.begin(), items.end(), [](item a, item b) {
        return a.dongia > b.dongia;
    });
    return tinhtoan(path3, w, items);
}

void print(int cach) {
	cout << endl;
    if (cach == 1)
    {
        cout << "Sap xep theo gia tri giam dan la toi uu nhat" << endl;
        cout << "Thu tu cac mon hang duoc chon: ";
        output(path1);
    }

    else if (cach == 2)
    {
        cout << "Sap xep theo trong luong tang dan la toi uu nhat" << endl;
        cout << "Thu tu cac mon hang duoc chon: ";
        output(path2);
    }

    else
    {
        cout << "Sap xep theo don gia giam dan la toi uu nhat" << endl;
        cout << "Thu tu cac mon hang duoc chon: ";
        output(path3);
    }
}

int main()
{
    cout << "Nhap W, N = "; 
    cin >> w >> n;

    items.resize(n);
    
    cout << "Nhap gia tri: "; 
    for (int i = 0; i < n; i++) cin >> items[i].giatri;

    cout << "Nhap trong luong: "; 
    for (int i = 0; i < n; i++) cin >> items[i].trongluong;

    // Tinh don gia
    for (int i = 0; i < n; i++) {
        items[i].index = i + 1;
        items[i].dongia = (double)items[i].giatri / items[i].trongluong;
    }

    int res1 = cach1(w, items);
    int res2 = cach2(w, items);
    int res3 = cach3(w, items);  

	cout << endl;
	cout << "Sap xep theo gia tri giam dan: " << res1 << endl;
    cout << "Sap xep theo trong luong tang dan: " << res2 << endl;
    cout << "Sap xep theo don gia giam dan: " << res3 << endl;
    int mx = max({res1, res2, res3});

    if (mx == res1)         
        print(1);
    if (mx == res2)    
        print(2);
    if (mx == res3)                    
        print(3);

    cout << "\nGia tri lon nhat co the thu duoc: " << mx << endl;
    return 0;
}
